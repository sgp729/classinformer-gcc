// Copyright (C) 2025 Georgiy Smykov
#pragma once

#include "rtti.h"

namespace storage {

inline const char node_name[] = "$classinformergccnode";

bool has_persistent_data();
rtti::vtables get_persistent_data();
void store_persistent_data(const rtti::vtables&);

} // storage
