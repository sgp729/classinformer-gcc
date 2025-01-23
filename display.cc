// Copyright (C) 2025 Georgiy Smykov
#include "display.h"

namespace display {

chooser::chooser(const rtti::vtables& vts)
        : vts(vts), chooser_t(CH_MODAL, 1, nullptr, nullptr, "Class Informer GCC", 0) {}

size_t idaapi chooser::get_count() const {
        return vts.size();
}

void idaapi
chooser::get_row(qstrvec_t* cols, int* icon, chooser_item_attrs_t* attrs, size_t n) const {

        cols->clear();
        cols->push_back(vts[n].type_name);
}

chooser_t::cbret_t idaapi chooser::enter(size_t n) {
        // go to selected vtable
        jumpto(vts[n].addr);
        return chooser_t::cbret_t{};
}

} // display
