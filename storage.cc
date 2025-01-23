// Copyright (C) 2025 Georgiy Smykov

#include "storage.h"
#include <netnode.hpp>
#include <cstring>

namespace storage {

bool has_persistent_data() {
        return exist(netnode(node_name, sizeof(node_name)));
}

rtti::vtables get_persistent_data() {

        rtti::vtables vts{};

        netnode node = netnode(node_name, sizeof(node_name));

        nodeidx_t index = node.supfirst();
        nodeidx_t end = node.suplast() / 2;

        if (index == BADNODE) {
                return {};
        }

        while (index <= end) {
                vts.emplace_back();

                node.supval(2*index, &vts.back().addr, sizeof(vts.back().addr));
                node.supstr(&vts.back().type_name, 2*index+1);

                index = node.supnext(index);
        }

        return vts;
}

void store_persistent_data(const rtti::vtables& vts) {

        netnode node = netnode(node_name, sizeof(node_name));
        if (not exist(node)) {
                node.create(node_name, sizeof(node_name));
        }
        node.altdel();
        node.supdel();

        for (nodeidx_t index = 0; index < vts.size(); ++index) {
                rtti::vtable vtable = vts[index];

                node.supset(2*index, &vtable.addr, sizeof(vtable.addr));

                char buf[512];
                std::strncpy(buf, vtable.type_name.c_str(), sizeof(buf));
                buf[511] = '\0';

                node.supset(2*index + 1, buf, strlen(buf));
        }
}

} // storage
