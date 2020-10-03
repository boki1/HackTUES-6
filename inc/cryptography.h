#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "block.h"
#include "internal.h"

namespace crypto {

    typedef ns_chain::ns_block::Message Type_msg;

    class HashManager {

        typedef void (*f_hash)(Type_msg);

        static const unsigned HASH_LENGTH = 64;

    private:
        f_hash Hash;

    public:
        HashManager(f_hash= nullptr);

    public:
        void DoHash(Type_msg);
    };

    class DigitalSignature {

    public:
        typedef ull SecretKey;
        typedef ull PublicKey;

        typedef struct {
            ull r;
            ull s; 
        } DSign;

        static const unsigned g_InvalidValue = 1;

        struct Params {
            ull p, q, g;
        };

        constexpr static const struct Params DEFAULT_PARAMS = {
                .p = 3670542389,
                .q = 47903,
                .g = g_InvalidValue
        };

    private:
        SecretKey GenerateSecretK(Params &);

        PublicKey GeneratePublicK(const Params &, const SecretKey);

        SecretKey ds_k_Secret;
        PublicKey ds_k_Public;
        Params ds_param;
        DSign ds_val;

    public:
        DigitalSignature();

    public:
        void GenerateUserKeys();

        int GetPublicKey();

        int EuclideanGCD(int, int);

        DSign Sign(ns_chain::ns_block::Entry &);

        bool Verify(ns_chain::ns_block::Entry &entry);
    };

}

#endif