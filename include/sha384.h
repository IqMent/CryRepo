//
// Created by iqment on 4/21/25.
//

#ifndef CRYREPO_SHA384_H
#define CRYREPO_SHA384_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define SHA384_HASH_BSIZE 48

typedef struct {
    unsigned char data[128];
    uint64_t datalen;
    uint64_t bitlen;
    uint64_t state[8];
}   SHA384_CTX;

int sha384_init(SHA384_CTX *ctx);
int sha384_update(SHA384_CTX *ctx, const unsigned char *data, const size_t len);
int sha384_final(SHA384_CTX *ctx, unsigned char hash[]);

#endif //CRYREPO_SHA384_H
