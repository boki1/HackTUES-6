#include <cstring>
#include "../inc/block.h"


namespace ns_chain {

    using namespace ns_block;

    Entry::Entry(char *msg)
    {
        this->timestamp = time(nullptr);
        this->flags = 0;
        if (msg) {
            memcpy(this->msg, msg, MSG_BYTES);
        }
        // leave 'ds' in this constructor
    }

    Entry &Entry::operator=(Entry &other) {
        this->flags = other.flags;
        this->timestamp = other.flags;
        this->ds = other.ds;
        memcpy(this->msg, other.msg, MSG_BYTES);
    }

    EntryPool::EntryPool() {
        this->length = 0;
    }

    bool EntryPool::EntryPoolAdd(Entry &entry) {
        if (this->length + 1 >= BLOCK_ENTRIES) {
            // new block
        }
        this->pool[length++] = entry;
    }

    void Entry::GetSigned(crypto::DigitalSignature &sign)
    {
       return;
    }

    EntryPool &EntryPool::operator=(const EntryPool &other)
    {

        for (auto &i : this->pool) {
            i.~Entry();
        }

        for (int i = 0; i < other.length; ++i) {
            this->pool[i] = (Entry &) other.pool[i];
        }

    }

}
