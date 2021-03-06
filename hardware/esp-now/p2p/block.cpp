#include "block.h"

namespace ns_chain {

    using namespace ns_block;

    BlockHeader::BlockHeader() {
        this->nonce = this->previous = this->selfhash = 0;
    }

    BlockHeader &BlockHeader::operator=(const BlockHeader &other) = default;

    Block &Block::BuildBlock(const BlockHeader &_header, const EntryPool &_pool) {
        this->bl_header = _header;
        this->bl_pool = _pool;
        return *this;
    }

    crypto::Type_msg Entry::GetMessage() {
        return this->msg;
    }





    DevRequest &DequeueRequest()
    {

    }

}
