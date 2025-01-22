// Copyright (C) 2025 Georgiy Smykov
#pragma once

#include <loader.hpp>
#include "init.h"

plugin_t PLUGIN = {
        IDP_INTERFACE_VERSION,
        PLUGIN_MOD | PLUGIN_UNL | PLUGIN_MULTI,
        init,
        nullptr,
        nullptr,
        "Extract RTTI information from GCC/Clang compiled binary",
        nullptr,
        "Class Informer GCC",
        nullptr
};
