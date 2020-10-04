#include <cstring>

#include "block.h"

Entry::Entry(int msg) {
    this->timestamp = time(nullptr);
    this->flags = 0;
    this->msg = msg;
    this->ds = nullptr;
}

Entry &Entry::operator=(Entry &other) {
    this->flags = other.flags;
    this->timestamp = other.flags;
    this->msg = other.msg;
    return *this;
}

EntryPool::EntryPool() {
    this->length = 0;
}

bool EntryPool::EntryPoolAdd(Entry &entry) {
    if (this->length + 1 >= BLOCK_ENTRIES) {
        // todo: here!
    }
    this->pool[length++] = entry;
    return false;
}

void Entry::GetSigned(DigitalSignature &sign) {
    return;
}

EntryPool &EntryPool::operator=(const EntryPool &other) {

    for (auto &i : this->pool) {
        i.~Entry();
    }

    for (int i = 0; i < other.length; ++i) {
        this->pool[i] = (Entry &) other.pool[i];
    }

    return *this;
}

