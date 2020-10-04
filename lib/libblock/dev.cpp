#include <iostream>

#include "block.h"

DeviceNode::DeviceNode(const int *const _mac_addr) {
    this->dev_mac[0] = _mac_addr[0];
    this->dev_mac[1] = _mac_addr[1];
    this->dev_state = IDLE;

    this->dev_begin = nullptr;
}

void DeviceNode::SetState(DevState _state) { this->dev_state = _state; }

unsigned DeviceNode::GetState() {
    return this->dev_state;
}

bool DeviceNode::ManageSingleRequest(DevRequest *cursor) {
    cursor = this->DequeueRequest();
    bool rv = false;
    if (cursor != nullptr)
        rv = cursor->Handle();
    rv = false;
    return rv;
}

DeviceNode &DeviceNode::ChainWith(Block &bl) {
    this->dev_begin = &bl;

    return *this;
}

// No return function
// Here we do all modifications and perform block operations such as transmit, receive, etc.
void DeviceNode::Loop() {

    auto *block = new Block();
    auto bh = BlockHeader(NO_HASH, NO_HASH, INITIAL_COUNTER);
    auto ep = EntryPool();

    block->BuildBlock(bh, ep);

    DevRequest *req;

    while (this->GetState() != TERM) {
        this->ManageSingleRequest(req);
    }
}

DevRequest::Type DevRequest::GetType() const {
    return this->dev_rq_type;
}

DevRequest::DevRequest(
        enum Type t, char *d)
        : dev_rq_type(t), buf(d) {}

void DeviceNode::EnqueueRequest(enum DevRequest::Type t) {
    this->dev_q_pending.push(DevRequest(t));
}

DevRequest *DeviceNode::DequeueRequest() {
    DevRequest *req = &this->dev_q_pending.front();
    this->dev_q_pending.pop();
    return req;
}


bool Transmit() {
    return false;
}

void Handle(const char *buff, DevRequest::Type r_type) {
    (void *) buff;
    (void) r_type;
}

