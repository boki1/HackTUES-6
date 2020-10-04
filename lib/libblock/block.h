#ifndef HACKTUES6_BLOCK_H
#define HACKTUES6_BLOCK_H

#include <ctime>
#include <cstdint>
#include <assert.h>
#include <cstring>

#include <queue>

#include "../params.h"
#include "../common_types.h"


class Entry {

public:

    enum EntryFlags {
        NotValidated = 0,
        IsValidated
    };

    void GetSigned(DigitalSignature &);

public:
    Entry(int msg = -1);
    // Entry(crypto::Type_msg, DigitalSignature, time_ , Flags);

    Entry &operator=(Entry &other); //= default;

    Type_msg GetMessage() const;

private:
    Type_msg msg;
    DigitalSignature *ds;
    time_t timestamp;
    char flags;
};

class Block;

class EntryPool {
private:
    Entry pool[BLOCK_ENTRIES];
    size_t length;

public:
    EntryPool &operator=(const EntryPool &);

public:
    EntryPool();

    bool EntryPoolAdd(Entry &);
};


class BlockHeader {

public:
    BlockHeader();

    BlockHeader(Type_hash, Type_hash, Type_hash);

    BlockHeader &operator=(const BlockHeader &other);

private:
    Type_hash nonce;
    Type_hash prev_hash;

    Type_hash this_hash;
};

class Block {

private:
    EntryPool bl_pool;
    BlockHeader bl_header;

public:
    Block() {}

    Block &operator=(Block &other) = default;

public:
    Block &BuildBlock(const BlockHeader _header, const EntryPool _pool);

};


class Miner {

public:
    Miner(int *mac_addr_t);

    Miner();

private:
    int mac_addr[2];
};

class DeviceNode;

enum DevState {
    IDLE = 0,
    BUSY,
    RECV,
    TMIT,
    VERF,
    TERM
};

static const unsigned short MAC_BYTES = 2;

static int *MACAddr(int _ints[], int count) {
    assert(count == 6);
    int *mac = new int[MAC_BYTES];
    mac[0] = (0x0 | (_ints[0] & 0xFF000000));
    mac[0] |= (_ints[1] & 0x00FF0000);
    mac[0] |= (_ints[2] & 0x0000FF00);
    mac[0] |= (_ints[3] & 0x000000FF);
    mac[1] |= (_ints[4] & 0xFF000000);
    mac[1] |= (_ints[5] & 0x00FF0000);
    return mac;
}

class DevRequest {
public:
    enum Type {
        PENDING_BLOCK,
        PENDING_ENTRY,
    };

public:
    DevRequest() = default;

    DevRequest(enum Type t, char *data = 0);

    void SetData(const char *buf);

    bool Transmit();

    bool Handle();

    enum Type GetType() const;

    const char *GetData() const;

private:
    enum Type dev_rq_type;
    char *buf;
    // todo: some form of return codes e.g. `struct ReqReturn`
};

class DeviceNode {
private:
    // MAC is actually 6B, but we get 8B
    int dev_mac[2];
    std::queue<DevRequest> dev_q_pending;

    DevState dev_state;
    Block *dev_begin;

public:
    DeviceNode(const int *const _mac_addr);

public:
    void SetState(DevState);

    unsigned GetState();

    bool ManageSingleRequest(DevRequest *cursor);

    void EnqueueRequest(enum DevRequest::Type);

    DevRequest *DequeueRequest();

    DeviceNode &ChainWith(Block &bl);

    void Loop();
};

#endif // _BLOCK_H
