// Copyright (C) 2025 Georgiy Smykov
#pragma once

#include "rtti.h"
#include <kernwin.hpp>

namespace display {

class chooser : public chooser_t {
public:
        chooser(const rtti::vtables&);
        virtual ~chooser() = default;

        virtual size_t idaapi get_count() const override;
        virtual void idaapi get_row(qstrvec_t*, int*, chooser_item_attrs_t*, size_t) const override;
        virtual chooser_t::cbret_t idaapi enter(size_t) override;

private:
        rtti::vtables vts;
};

} // display
