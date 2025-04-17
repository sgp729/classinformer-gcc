// Copyright (C) 2025 Georgiy Smykov
#pragma once

#include <segment.hpp>
#include <vector>

namespace rtti {

struct vtable {
        ea_t addr;
        qstring type_name;
};
using vtables = std::vector<vtable>;

void export_segment(vtables&, const char*);

bool is_typeinfo(const qstring&);
qstring get_typeinfo_class_name(const qstring&);

} // rtti
