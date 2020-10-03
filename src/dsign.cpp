#include <cstdlib>
#include <cmath>
#include <cassert>

#include "../inc/cryptography.h"
#include "../inc/internal.h"

namespace crypto {

    DigitalSignature::DigitalSignature()
            : ds_k_Secret(0), ds_k_Public(0), ds_val(DEFAULT_DS_VALUE), ds_param(DEFAULT_PARAMS) {}

    void DigitalSignature::GenerateUserKeys() {
        SecretKey x = GenerateSecretK(this->ds_param);
        PublicKey y = GeneratePublicK(this->ds_param, x);

        this->ds_k_Public = y;
        this->ds_k_Secret = x;
    }

    int DigitalSignature::GetPublicKey() const {
        return this->ds_k_Public;
    }

    DigitalSignature &DigitalSignature::operator=(const DigitalSignature &other)
    {
        this->ds_k_Public = other.ds_k_Public;
        this->ds_param = other.ds_param;
        this->ds_k_Secret = other.ds_k_Secret;
        this->ds_val = other.ds_val;
        return *this;
    }

    DigitalSignature::DSign DigitalSignature::Sign(ns_chain::ns_block::Entry &entry) {

        ull k, r = 0, tmp;
        while (r == 0) {
            k = (rand() % (this->ds_param.q - 1)) + 1;
            tmp = ((ull) pow(this->ds_param.g, k) % this->ds_param.p);
            r = tmp % this->ds_param.q;
        }

        ull s = 0;
        ull tmp1;
        while (s == 0) {
            k = (rand() % (this->ds_param.q - 1)) + 1;
            tmp1 = this->ds_k_Secret * r;

            /*eucledion algorithm*/

        }

        return DEFAULT_DS_VALUE;
    }

    bool DigitalSignature::Verify(ns_chain::ns_block::Entry &entry) {
        return false;
    }

    DigitalSignature::SecretKey DigitalSignature::GenerateSecretK
            (DigitalSignature::Params &params) {

        auto _g = [=]() -> ull {
            ul h = 2 + (rand() % (this->ds_param.p - 2));
            ul expon, tmp;

            do {
                expon = (this->ds_param.p - 1) / this->ds_param.q;
                tmp = pow(h, expon);
                this->ds_param.g = tmp % this->ds_param.p;
            } while (this->ds_param.g == g_InvalidValue);

            return this->ds_param.g;
        };

        this->ds_param.g = _g();
        SecretKey x = (rand() % (this->ds_param.q - 1)) + 1;
        this->ds_k_Secret = x;
        return x;
    }

    DigitalSignature::PublicKey DigitalSignature::GeneratePublicK
            (const DigitalSignature::Params &params, const DigitalSignature::SecretKey x) {
        PublicKey y = ( (ull) pow(params.g, x)) % params.g;
        this->ds_k_Public = y;
        return y;
    }

}