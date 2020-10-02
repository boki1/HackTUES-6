#include "inc/encryption.h"
#include <math.h>


namespace crypto {
    CryptoManager::CryptoManager() 
    {
        this -> RandomNumber = 2 + (rand() % (this -> KeyLengthBitPrime - 2));

        do
        {
            unsigned long int power = (this -> KeyLengthBitPrime - 1) / this -> ModuloBitPrime;
            this -> g = (int) pow((double)this -> RandomNumber, (double)power) % this -> ModuloBitPrime;
        } while (g == 1);

           
    }

    CryptoManager::CryptoManager(f_crypt _c, f_decrypt _d) 
    {
        this-> Sign = _c;
        this-> Verify = _d;
    
    }

    char *CryptoManager::DoCrypt(const char *msg)
    {
        this-> Sign(msg, this -> GetPublicKey());
    }

    char *CryptoManager::DoDecrypt(const char *CryptedMsg)
    {
        this -> Verify(CryptedMsg, this -> GetSecretKey());
    }
    
    void CryptoManager::GenerateUserKeys(unsigned long long int g, const unsigned long long KeyLengthBitPrime, const unsigned  ModuloBitPrime)
    {
        this -> UserKeys.SecretKey = 1 + (rand() % (this -> ModuloBitPrime - 1));
        this -> UserKeys.PublicKey = (int) pow(this -> g, this -> UserKeys.SecretKey) % this -> KeyLengthBitPrime;
    }

    int CryptoManager::GetPublicKey()
    {
        return this -> UserKeys.PublicKey;
    }
    
    int CryptoManager::GetSecretKey()
    {
        return this -> UserKeys.SecretKey;
    }

    HashManager::HashManager(f_hash _h)
    {
        this -> Hash = _h;
    }

    void HashManager::DoHash(const char *msg)
    {
        this -> Hash(msg);
    }

    int HashManager::GetHashLength()
    {
        return this -> HASH_LENGTH;
    }


}