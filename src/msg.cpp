#include <cstring>
#include "../inc/block.h"


namespace ns_chain {

    using namespace ns_block;

    Message::Message() {
        memset(this->msg_data, 0, MSG_BYTES);
        this->digital_sign = nullptr;
        this->flags = 0;
        this->timestamp = 0;
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

    MessagePool::MessagePool() {
       for (auto msg: this->pool) {
          msg = Message();
       }
    }

//    MessagePool &MessagePool::operator=(const MessagePool &other) {
//        for (int i = 0; i < N_MESG_POOL &&
//                            other.pool[i]; ++i) {
//            this->pool[i] = other.pool[i];
//        }
//        for (auto msg: other.pool) {
//           this->pool[]
//        }
//        memcpy(this->pool, other.pool, sizeof(Message) * N_MESG_POOL);
//    }

}
