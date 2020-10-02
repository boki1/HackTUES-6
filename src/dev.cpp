#include <iostream>
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

        while (this->GetState() != D_TERMINATE) {

            // do stuff

//            std::cout << "Receiving ..." << std::endl;
        }

    }

}