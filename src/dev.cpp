#include <iostream>
#include <block.h>
#include "../inc/block.h"


namespace ns_chain {

    using namespace ns_node;

    DeviceNode::DeviceNode(int *_mac_addr) {
        this->dev_mac[0] = _mac_addr[0];
        this->dev_mac[1] = _mac_addr[1];
        this->dev_state = BL_RECV;

        this->dev_begin = nullptr;
    }


    void DeviceNode::SetState(ns_node::DevState _state) {
        this->dev_state = _state;
    }

    unsigned DeviceNode::GetState() {
        return this->dev_state;
    }

    // No return function
    // Here we do all modification and perform operations such as transmit, receive, etc.
    void DeviceNode::Loop() {

        ns_block::Block block;

        while (this->GetState() != D_TERMINATE) {
            this->SetState(BL_RECV);

            // Call Receive on the network manager thingy
//            while (!ReceiveBlock())
            // Somehow verify that this is a block

            this->SetState(BUSY);
            // call a function which performs the following checks:
            // is the block verified
            // if so [...]
            //
            // just follow the 'algo-sheme' file

        }
    }

    DevRequest::Type DevRequest::GetType() const {
        return this->dev_rq_type;
    }

    DevRequest::DevRequest(enum Type t)
            : dev_rq_type(t) {}

    void DeviceNode::EnqueueRequest(enum DevRequest::Type t)
    {
        this->dev_q_pending.push(DevRequest(t));
    }

    DevRequest::Type ns_node::DeviceNode::DequeueRequest() {
        enum DevRequest::Type t = this->dev_q_pending.front().GetType();
        this->dev_q_pending.pop();
        return t;
    }

    bool Transmit()
    {
       return false;
    }
    
    void Handle(const char *buff, DevRequest::Type r_type)
    {
        (void *) buff;
        (void) r_type;
    }

}