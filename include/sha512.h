// Author: iqMent
// Copyright: GNU Public
// Description: SHA512 implementation
// Date: 25/03/2025
// File: include/sha512.h

#ifndef SHA512_H
#define SHA512_H

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define SHA512_HASH_BSIZE 64

typedef struct {
    unsigned char data[128];
    unsigned long long datalen;
    unsigned long long bitlen;
    unsigned long long state[8];
} SHA512_CTX;

int sha512_init(SHA512_CTX *ctx);
int sha512_update(SHA512_CTX *ctx, const unsigned char *data, const size_t len);
int sha512_final();

#endif //SHA512_H
