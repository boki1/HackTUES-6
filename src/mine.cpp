#include "../inc/block.h"
#include "../inc/cryptography.h"

namespace mining {

    class Miner {

    public:
       Miner(int *mac_addr_t);
       Miner();

    private:
        int mac_addr[2];
    };

}
