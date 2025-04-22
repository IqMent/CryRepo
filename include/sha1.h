//
// Created by iqment on 4/21/25.
//

#ifndef CRYREPO_SHA1_H
#define CRYREPO_SHA1_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define SHA1_HASH_BSIZE 20

typedef struct {
    unsigned char data[64];
    uint32_t datalen;
    uint64_t bitlen;
    uint32_t state[5];
} SHA1_CTX;

int sha1_init(SHA1_CTX *ctx);
int sha1_update(SHA1_CTX *ctx, const unsigned char *data, const size_t len);
int sha1_final(SHA1_CTX *ctx, unsigned char hash[]);

#endif //CRYREPO_SHA1_H
