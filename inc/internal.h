#ifndef HACKTUES_6_INTERNAL_H
#define HACKTUES_6_INTERNAL_H


typedef unsigned long ul;
typedef unsigned long long ull;

#define BLOCK_ENTRIES           128
#define BLK_STORAGE_SLOTS       128
#define BLK_MOD_SLOTS           16

#define MSG_BYTES               3

namespace ns_chain { namespace ns_block { class Message; } }
namespace crypto { class DigitalSignature; }

#endif //HACKTUES_6_INTERNAL_H
