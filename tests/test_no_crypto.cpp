#include "../inc/block.h"

namespace tests {

    class TestNoCrypto {

        static int TestDeviceNode() {
            using namespace ns_chain::ns_node;
            int arr[6] = {1, 2, 3, 4, 5, 6};
            int *mac = MACAddr(arr, 6);
            DeviceNode dnod = new DeviceNode(mac);
        }

    };

}
