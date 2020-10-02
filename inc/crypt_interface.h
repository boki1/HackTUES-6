#ifndef HACKTUES6_CRYPT_INTERFACE_H
#define HACKTUES6_CRYPT_INTERFACE_H

// TODO: remove defines

#define HASH_TOGETHER(h, other)     HASH_FUNC(h##other)
#define HASH_FUNC(f)
#define HASH_FUNC_LENGTH    0
#define HASH    const char *const *
#define DS      void * // digital digital_sign
#define MAC_ADDR   const char *const *


#endif //HACKTUES6_CRYPT_INTERFACE_H
