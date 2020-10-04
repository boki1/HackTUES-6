#include <cmath>
#include <cstdlib>

#include "../inc/cryptography.h"

namespace crypto {

    HashManager::HashManager(f_hash _h) {
        this->hash_function = _h;
    }

    ull HashManager::DoHash(Type_msg msg) {
        return this->DoHash(msg);
    }

}
