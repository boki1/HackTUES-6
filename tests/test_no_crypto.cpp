#include "../inc/block.h"

namespace tests {

    class TestNoCrypto {

    public:
        static int TestDeviceNode() {
            using namespace ns_chain::ns_node;
            int arr[6] = {1, 2, 3, 4, 5, 6};
            int *mac = MACAddr(arr, 6);
            DeviceNode *dnod = new DeviceNode(mac);
            dnod->Loop();

            return 1;
        }

        static

    };
}

int main() {
    tests::TestNoCrypto::TestDeviceNode();

    return 0;
}
