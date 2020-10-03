#include "../inc/block.h"

namespace ns_chain {

    using namespace ns_block;

    BlockHeader::BlockHeader() {
        this->nonce = nullptr;
        this->previous = nullptr;
    }

    BlockHeader &BlockHeader::operator=(const BlockHeader &other) = default;
    
    char *Entry::GetMessage()
    {
        return this->msg;
    }
}

