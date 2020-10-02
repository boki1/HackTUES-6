
#ifndef HACKTUES6_BLOCK_H
#define HACKTUES6_BLOCK_H

#include <ctime>
#include <cstdint>
#include <cstring>

#include "crypt_interface.h"

namespace ns_chain {
    namespace ns_block {

        class MessagePool {

        private:
            class Message {
            public:
                Message()
                    : msg_data(nullptr), signature(nullptr), flags(0)
                {
                    timestamp = std::time(nullptr);
                }

                Message(char *_msg_data, time_t &_timestamp, DS _signature, uint32_t &_flags)
                    : msg_data(_msg_data), signature(_signature), flags(_flags)
                {
                    timestamp = std::time(nullptr);
                }

                ~Message() {
                    delete[] msg_data;

                    // todo: check whether new is called on signature
                    // delete[] signature;
                }

            private:
                char *msg_data; // TODO: figure out some 'protocol' for the data stored in the data field
                time_t timestamp;
                DS signature;
                uint32_t flags;
            };

        private:
            static const int N_MESG_POOL = 3;
            Message pool[N_MESG_POOL];

        public:
            MessagePool();
            ~MessagePool();
            MessagePool &operator=(const MessagePool &other)
            {
                // todo:
                // NOT BUG-FREE
                memcpy(this->pool, other.pool, sizeof(Message) * N_MESG_POOL);
            }
        };

        MessagePool::MessagePool() {

           // initialize an empty message pool w/ empty messages
           // note: this->timestamp is equal to the CURRENT TIME; cannot be initizalized manually
           for (auto msg: this->pool) {
               msg = Message();
           }

        }

        MessagePool::~MessagePool() {}

        namespace ns_header {

            class MerkleNode {
            public:
                MerkleNode();
                ~MerkleNode();


            private:
                HASH _hash;
                MerkleNode &left, &right;
            };

            class MerkleTree {

                MerkleTree();
                ~MerkleTree();

                bool MerkleRootCheck(MessagePool &);

            private:
                MerkleNode &root;

            };

            bool MerkleTree::MerkleRootCheck(MessagePool &m_pool) {

            }

            class BlockHeader {

            public:
                BlockHeader() : msgs(MessagePool()){
                    // todo:
                    // set proper initial value for field `nonce`
                    this->nonce = 0;

                    // set proper initial value for field `previos`
                    this->previous = 0;
                }

                BlockHeader &operator=(const BlockHeader &other)
                {
                    this->previous = other.previous;
                    this->nonce = other.nonce;
                    this->msgs = other.msgs;
                }

                ~BlockHeader();

            private:
                MessagePool msgs;
                HASH nonce;
                HASH previous;
            };

        }

        class Block {
        private:
            ns_header::BlockHeader bl_header;


        public:
            int BlockTransmitPrepare()
            {
               time_t _now = time(0) ;
               HASH_TOGETHER(this->bl_header.root_hash, _now);

               // todo:
               // do smth with this combined hash
            }

            Block &operator=(Block &other) {
                this->bl_header = other.bl_header;
            }

            Block() {}
            ~Block() {}
            Block(const Block &other) {
               this->bl_header = other.bl_header;
            }
        };

    }

    namespace ns_node {
        /*
         * Used to descrive a 'device node'; each "station" is a device node w/ a unique 'id'
         */
        class DevNode {

        private:
            uint32_t flags;
            MAC_ADDR unique_id;

            enum DevNodeState {
                IDLE,
                BL_RECV,
                BL_TRNS,
                BL_VERF
            } nod_state;

            // TODO: figure out a 'block saving mechanism'
            // for now a ptr to the first block would be fine
            ns_block::Block begin;

        public:
            DevNode(MAC_ADDR nod_id)
                : begin(ns_chain::ns_block::Block())
            {
                // todo: genesis block
                // ch. if a genesis block is for the whole chain or per device
                // if the chain -> figure out a propermway to initilize the 'head' field
                // otherwise  -> just create a genesis block and assign the head there
                // initialize genesis block

                // for now lets just create an empty block w/ an empty msgpool

               flags = 0;
               unique_id = nod_id;
               nod_state = IDLE;
            }
            ~DevNode();
        };
    }

}

#endif // header lock
