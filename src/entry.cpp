#include <cstring>
#include "../inc/block.h"


namespace ns_chain {

    using namespace ns_block;

    Entry &Entry::operator=(Entry &other) {
        this->flags = other.flags;
        this->timestamp = other.flags;
        this->ds = other.ds;
        memcpy(this->msg, other.msg, MSG_BYTES);
    }

    EntryPool::EntryPool() = default;

    EntryPool::EntryPool(Entry _pool[], size_t _length) {
        this->length = _length;
        for (int i = 0; i < _length; ++i) {
            this->pool = _pool[i];
        }
    }

    Message::Message(const char *_msg_data, DS dig_sign) {
        memcpy(this->msg_data, _msg_data, this->MSG_BYTES * sizeof(*this->msg_data));
        this->timestamp = std::time(nullptr);
        this->digital_sign = dig_sign;

        // Consider marking some thinks here such as:
        // digital signature assigned
        // msg assigned
        this->flags = 0;
    }

    EntryPool::EntryPool() {
        for (auto msg: this->pool) {
            msg = Message();
        }
    }

}
