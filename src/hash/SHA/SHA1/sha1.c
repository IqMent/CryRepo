//
// Created by iqment on 4/19/25.
//

#include "sha1.h"

int sha1_init(SHA1_CTX *ctx) {
    if (!ctx)
        return -1;
    ctx->state[0] = H0;
    ctx->state[1] = H1;
    ctx->state[2] = H2;
    ctx->state[3] = H3;
    ctx->state[4] = H4;
    ctx->datalen = 0;
    ctx->bitlen = 0;
    return 0;
}

int sha1_update(SHA1_CTX *ctx, const unsigned char *data, const size_t len) {
    if (!ctx || !data || len == 0)
        return -1;

    return 0;
}
