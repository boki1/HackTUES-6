#ifndef ENCRYPTION_H
#define ENCRYPTION_H

namespace crypto
{

    typedef void (*f_crypt)(const char *, int /*Secret key*/);
    typedef void (*f_decrypt)(const char *, int /* private key */);

    typedef struct KeyPair
    {
        int SecretKey;
        int PublicKey;
    } KeyPair;

    class CryptoManager {
    private:
        static const unsigned long long KeyLengthBitPrime = 3670542389;
        static const unsigned  ModuloBitPrime = 47903;
        unsigned long int RandomNumber;
        unsigned long long int g;

        KeyPair UserKeys;

        CryptoManager &operator=(const CryptoManager &NewManager);

        f_crypt Sign;
        f_decrypt Verify;
    public:
        CryptoManager();
        CryptoManager(f_crypt, f_decrypt);

        void GenerateUserKeys(unsigned long long int g, const unsigned long long KeyLengthBitPrime, const unsigned  ModuloBitPrime);
        int GetPublicKey();
        int GetSecretKey();

        char *DoCrypt(const char *);        
        char *DoDecrypt(const char *);

    };


    typedef void (*f_hash)(const char *);

    class HashManager {
    private:
        // in bytes
        static const unsigned HASH_LENGTH = 64;
        f_hash Hash;

    public:
        HashManager();
        HashManager(f_hash);

        int GetHashLength();
        void DoHash(const char *);
    };
}



#endif