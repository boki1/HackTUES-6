#ifndef HACKTUES6_BLOCK_H
#define HACKTUES6_BLOCK_H

#include <ctime>
#include <cstdint>
#include <assert.h>
#include <cstring>

#include "crypt_interface.h"

namespace ns_chain {

    namespace ns_block {

        class Message {

        public:
            Message();
            Message(const char *, DS);

        private:
            static const char MSG_BYTES = 3;

            char msg_data[MSG_BYTES]; // TODO: figure out some 'protocol' for the data stored in the data field
            time_t timestamp;
            DS digital_sign;
            uint8_t flags;
        };

        class MessagePool {

        private:
            // todo: set some usable value
            static const int N_MESG_POOL = 0;
            Message pool[N_MESG_POOL];

        public:
            MessagePool();
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
            MessagePool bl_pool;
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

        // todo:
        // make sure the masks are appropriate for the data type of the arguments
        static int *MACAddr(int _ints[], int count) {
            assert(count == 6);
            int *mac = new int[2];
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
