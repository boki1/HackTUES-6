#include <cmath>
#include <cstdlib>

#include "../inc/cryptography.h"

namespace crypto {

    HashManager::HashManager(f_hash _h) {
        this->Hash = _h;
    }

    void HashManager::DoHash(Type_msg msg) {
        this->Hash(msg);
    }

}