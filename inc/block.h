#ifndef HACKTUES6_BLOCK_H
#define HACKTUES6_BLOCK_H

#include <ctime>
#include <cstdint>
#include <assert.h>
#include <cstring>

#include "internal.h"
#include "cryptography.h"

namespace ns_chain {

    namespace ns_block {

        class Entry {

        public:
            enum EntryFlags {
                NotValidated = 0,
                IsValidated
            };

        public:
            Entry();
            Entry(Msg, Ds, Timestamp, Flags);

            Entry &operator=(Entry &other);ww

        private:
            char msg[2];
            crypto::DigitalSignature ds;
            time_t timestamp;
            char flags;
        };

        class EntryPool {

        private:
            Entry pool[BLOCK_ENTRIES];
            size_t length;

        public:
            EntryPool();
            EntryPool(Entry _pool[]);
        };

        class BlockHeader {

        public:
            BlockHeader();
            BlockHeader &operator=(const BlockHeader &other);

        private:
            HASH nonce;
            HASH previous;
        };

        class Block {

        private:
            EntryPool bl_pool;
            BlockHeader bl_header;

        public:
            Block() {}

            Block &operator=(Block &other) = default;

        public:


        };

    }

    namespace ns_node {

        enum DevState {
            IDLE = 0,
            BL_RECV,
            BL_TRNS,
            BL_VERF,

            D_TERMINATE
        } ;

        static const unsigned short MAC_BYTES = 2;

        static int *MACAddr(int _ints[], int count) {
            assert(count == 6);
            int *mac = new int[MAC_BYTES];
            mac[0] = (0x0 | (_ints[0] & 0xFF000000));
            mac[0] |= (_ints[1] & 0x00FF0000);
            mac[0] |= (_ints[2] & 0x0000FF00);
            mac[0] |= (_ints[3] & 0x000000FF);
            mac[1] |= (_ints[4] & 0xFF000000);
            mac[1] |= (_ints[5] & 0x00FF0000);
            return mac;
        }

        class DeviceNode {

        private:
            // MAC is actually 6B, but we get 8B
            int dev_mac[2];

            ns_node::DevState dev_state;
            ns_block::Block *dev_begin;

        public:
            DeviceNode(int *_mac_addr);

        public:
            void SetState(ns_node::DevState);
            unsigned GetState();

            void Loop();

        };
    }
}

#endif // _BLOCK_H
