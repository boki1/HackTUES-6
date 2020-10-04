#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "internal.h"

namespace crypto {

    typedef int Type_msg;
    typedef ull Type_hash;

    class HashManager {

        typedef ull (*f_hash)(Type_msg);

        static const unsigned HASH_LENGTH = 64;

    private:
        f_hash hash_function;
        Type_hash stored_hash;

    public:
        HashManager(f_hash=nullptr);

    public:
        ull DoHash(Type_msg);
    };

    class DigitalSignature {

    public:
        typedef ull SecretKey;
        typedef ull PublicKey;

        struct DSign {
            ull r;
            ull s;
        } DEFAULT_DS_VALUE = {.r=0, .s=0};

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

        static int BruteForceModMult(int num1, int num2);

        SecretKey ds_k_Secret;
        PublicKey ds_k_Public;
        Params ds_param;
        DSign ds_val;

    public:
        DigitalSignature();
        DigitalSignature &operator=(const DigitalSignature &);

    public:
        void GenerateUserKeys();

        int GetPublicKey() const;

        DSign *Sign(ns_chain::ns_block::Entry &);

        bool Verify(ns_chain::ns_block::Entry &entry);
    };

}

#endif
