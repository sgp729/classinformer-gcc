// Copyright (C) 2025 Georgiy Smykov
#include "class_informer.h"
#include "rtti.h"
#include "display.h"
#include "storage.h"
#include <kernwin.hpp>

namespace class_informer {

bool plugin::run(size_t arg) {

        rtti::vtables vts;

        if (storage::has_persistent_data()) {

                int ans = ask_yn(ASKBTN_YES, "There is an existing VTable DB; Open it?");
                if (ans == ASKBTN_CANCEL) {
                        return true;
                }
                else if (ans == ASKBTN_YES) {
                        vts = storage::get_persistent_data();
                }
                else {
                        goto nodata;
                }
        }
        else {
nodata:
                rtti::export_segment(vts, ".data.rel.ro");
                rtti::export_segment(vts, ".data.rel.ro.local");
                storage::store_persistent_data(vts);
        }

        chooser_t* ch = new display::chooser(vts);
        ch->choose();

        return true;
}

} // class_informer
