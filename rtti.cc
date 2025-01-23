// Copyright (C) 2025 Georgiy Smykov

#include "rtti.h"
#include <bytes.hpp>
#include <name.hpp>
#include <segment.hpp>
#include <pro.h>

namespace rtti {

vtables find_vtables_in_segment(const char* name) {

        segment_t* segm = get_segm_by_name(name);
        if (segm == nullptr) {
                return {};
        }

        vtables ts;

        ea_t start = segm->start_ea;
        ea_t end = segm->end_ea;

        for (ea_t ptr = start; ptr < end; ptr += 8) {
                // the first vtable element is 0x0 (offset to this)
                if (get_qword(ptr) != 0) {
                        continue;
                }

                // the second vtable element is typeinfo for class
                ea_t typeinfo_ptr = get_qword(ptr + 8);
                qstring mangled_typeinfo_name = get_name(typeinfo_ptr);

                if (not is_typeinfo(mangled_typeinfo_name)) {
                        continue;
                }

                qstring class_name = get_typeinfo_class_name(mangled_typeinfo_name);
                ts.emplace_back(ptr, class_name);
        }

        return ts;
}

bool is_typeinfo(const qstring& name) {

        // typeinfo mangled name starts with _ZTI...
        return name.starts_with("_ZTI");
}

qstring get_typeinfo_class_name(const qstring& name) {

        qstring demangled_name = demangle_name(name.c_str(), DEMNAM_NAME);
        // class name follows the ' symbol in demangled name
        return demangled_name.substr(demangled_name.find('\'') + 1);
}

} // rtti
