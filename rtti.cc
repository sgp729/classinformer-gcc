// Copyright (C) 2025 Georgiy Smykov

#include "rtti.h"
#include <bytes.hpp>
#include <name.hpp>
#include <segment.hpp>
#include <pro.h>

namespace rtti {

void export_segment(vtables& vts, const char* name) {

        segment_t* segm = get_segm_by_name(name);
        if (segm == nullptr) {
                return;
        }

        ea_t start = segm->start_ea;
        ea_t end = segm->end_ea;

        size_t ptr_size = inf_is_64bit() ? 8 : 4;

        for (ea_t ptr = start; ptr < end; ptr += ptr_size) {
                // the first vtable element is 0x0 (offset to this)
                if (ptr_size == 4 and get_dword(ptr) != 0) {
                        continue;
                }
                else if (ptr_size == 8 and get_qword(ptr) != 0){
                        continue;
                }

                // the second vtable element is typeinfo for class
                ea_t typeinfo_ptr{};
                if (ptr_size == 4) {
                        typeinfo_ptr = get_dword(ptr + ptr_size);
                }
                else {
                        typeinfo_ptr = get_qword(ptr + ptr_size);
                }
                qstring mangled_typeinfo_name = get_name(typeinfo_ptr);

                if (not is_typeinfo(mangled_typeinfo_name)) {
                        continue;
                }

                qstring class_name = get_typeinfo_class_name(mangled_typeinfo_name);
                vts.emplace_back(ptr, class_name);
        }
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
