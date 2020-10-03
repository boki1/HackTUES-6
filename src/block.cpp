#include "../inc/block.h"

namespace ns_chain {

    using namespace ns_block;

    BlockHeader::BlockHeader() {
        this->nonce = this->previous = this->selfhash = 0;
    }

    BlockHeader &BlockHeader::operator=(const BlockHeader &other) = default;
    
    crypto::Type_msg Entry::GetMessage()
    {
        return this->msg;
    }

    Block &Block::BuildBlock(const BlockHeader &_header, const EntryPool &_pool) {
        this->bl_header = _header;
        this->bl_pool = _pool;
        return *this;
    }

    Message::Message(char *msg)
    {
        this -> msg = msg;
    }
}

