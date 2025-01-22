// Copyright (C) 2025 Georgiy Smykov
#pragma once

#include <idp.hpp>

namespace class_informer {

class plugin : public plugmod_t {
public:
        plugin() = default;
        virtual ~plugin() = default;

        virtual bool idaapi run(size_t) override;
};

} // class_informer
