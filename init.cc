// Copyright (C) 2025 Georgiy Smykov

#include "init.h"
#include "class_informer.h"
#include "plugin_info.h"

plugmod_t* idaapi init() {
        return new class_informer::plugin;
}
