#include "block.h"


BlockHeader::BlockHeader()
        : this_hash(0), prev_hash(0), nonce(0) {}

BlockHeader::BlockHeader(Type_hash t_h, Type_hash pr_h, Type_hash n)
        : this_hash(t_h), prev_hash(pr_h), nonce(n) {}

BlockHeader &BlockHeader::operator=(const BlockHeader &other) = default;

Block &Block::BuildBlock(const BlockHeader _header, const EntryPool _pool) {
    this->bl_header = _header;
    this->bl_pool = _pool;
    return *this;
}

Type_msg Entry::GetMessage() const {
    return this->msg;
}

