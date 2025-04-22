// Author: iqMent
// Copyright: GNU Public
// Description: SHA256 implementation
// Date: 25/03/2025

#include "../../../../include/sha256.h"
#include <string.h>
//Documentation: https://csrc.nist.gov/files/pubs/fips/180-2/final/docs/fips180-2.pdf

#define ROT_L(x, n) ((x << n) | (x >> (32 - n)))
/*
 * The rotate left (circular left shift) operation, ROTL n(x), where x is a w-bit word and n
 * is an integer with 0 £ n < w, is defined by
 * ROTL n(x) = (x << n) v (x >> w - n).
 * Thus, ROTL n(x) is equivalent to a circular shift (rotation)
 * of x by n positions to the left.
*/
#define ROT_R(x, n) ((x >> n) | (x << (32 - n)))
/*
 * The rotate right (circular right shift) operation ROTR n(x), where x is a w-bit word
 * and n is an integer with 0 <= n < w, is defined by
 * ROTRn(x) = (x >> n) v (x << w - n).
 * Thus, ROTR n(x) is equivalent to a circular shift (rotation)
 * of x by n positions to the right
*/
#define SHR(x, n) (x >> n)
/*
 * The right shift operation SHR n(x), where x is a w-bit word and n is an integer with 0
 * <= n < w, is defined by SHR n(x) = x >> n.
*/

/*
 * SHA256 - Function's Definitions
*/

#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
//Big sigma function's
#define SIGMA0(x) (ROT_R(x, 2) ^ ROT_R(x, 13) ^ ROT_R(x, 22))
#define SIGMA1(x) (ROT_R(x, 6) ^ ROT_R(x, 11) ^ ROT_R(x, 25))
//Small sigma function's
#define sigma0(x) (ROT_R(x, 7) ^ ROT_R(x, 18) ^ SHR(x, 3))
#define sigma1(x) (ROT_R(x, 17) ^ ROT_R(x, 19) ^ SHR(x, 10))

typedef unsigned char   byte;
typedef unsigned int    word; // 4 bytes

// Constants
static const unsigned int SHA256_INITIAL_HASH_CONSTANT[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

static const unsigned int SHA256_CONSTANT[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
// £ - <=
/*
SHA-256 may be used to hash a message, M, having a length of l bits, where 0 £ l < . The
algorithm uses 1) a message schedule of sixty-four 32-bit words, 2) eight working variables of 32
bits each, and 3) a hash value of eight 32-bit words. The final result of SHA-256 is a 256-bit
message digest.
The words of the message schedule are labeled W0 , W1 ,…, W63 . The eight working variables are
(i ) (i) (i )
labeled a, b, c, d, e, f, g, and h. The words of the hash value are labeled H , H ,K, H ,0 1 7
which will hold the initial hash value, H(0), replaced by each successive intermediate hash value
(after each message block is processed), H(i), and ending with the final hash value, H(N). SHA
256 also uses two temporary words, T1 and T2 .
Appendix B gives several detailed examples of SHA-256.
 */
// l = message for example "abc"
// l = 01100001 01100010 01100011
// We have to add 1 bit to end of the message: 01100001 01100010 01100011 1
// Then we have to add 0 bits until the length of the message is 448 bits
// Then we have to add the length of the message as a 64-bit integer

#define ONEBIT 0x80


/******************Functions Implementation******************/
static void sha256_transform(SHA256_CTX *ctx, const byte data[]){
    word a, b, c, d, e, f, g, h, i, j;
    word t1, t2;
    word m[64];
    for (i = 0, j = 0; i < 16; i++, j+=4)
        m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
    for ( ; i < 64; i++){
        m[i] = sigma1(m[i - 2]) + m[i - 7] + sigma0(m[i - 15]) + m[i - 16];
    }
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];
    for (size_t i = 0; i < 64; i++){
        t1 = h + SIGMA1(e) + CH(e, f, g) + SHA256_CONSTANT[i] + m[i];
        t2 = SIGMA0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

int sha256_init(SHA256_CTX *ctx){ // 1 - success, -1 - fail
    if (ctx == NULL)
        return (0);
    if (!ctx)
        return (0);
    ctx->datalen = 0;
    ctx->bitlen = 0;
    ctx->state[0] = SHA256_INITIAL_HASH_CONSTANT[0];
    ctx->state[1] = SHA256_INITIAL_HASH_CONSTANT[1];
    ctx->state[2] = SHA256_INITIAL_HASH_CONSTANT[2];
    ctx->state[3] = SHA256_INITIAL_HASH_CONSTANT[3];
    ctx->state[4] = SHA256_INITIAL_HASH_CONSTANT[4];
    ctx->state[5] = SHA256_INITIAL_HASH_CONSTANT[5];
    ctx->state[6] = SHA256_INITIAL_HASH_CONSTANT[6];
    ctx->state[7] = SHA256_INITIAL_HASH_CONSTANT[7];
    return (1);
}

int sha256_update(SHA256_CTX *ctx, const unsigned char *data, const size_t len){ // 1 - success, 0 - fail
    if (!ctx || !data || len <= 0)
        return (0);
    for (size_t i = 0; i < len; i++){
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if (ctx->datalen == 64){
            sha256_transform(ctx, ctx->data);
            ctx->bitlen += 512;
            ctx->datalen = 0;
        }
    }
    return (1);
}

int sha256_final(SHA256_CTX *ctx, byte hash[]){ // 1 - success, 0 - fail
    if (!ctx || !hash)
        return (0);
    word i;
    i = ctx->datalen;
    if (ctx->datalen < 56){
        ctx->data[i++] = 0x80;
        while (i < 56)
            ctx->data[i++] = 0x00;
    }
    else{
        ctx->data[i++] = 0x80;
        while (i < 64)
            ctx->data[i++] = 0x00;
        sha256_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }
    ctx->bitlen += ctx->datalen * 8;
    ctx->data[63] = ctx->bitlen;
    ctx->data[62] = ctx->bitlen >> 8;
    ctx->data[61] = ctx->bitlen >> 16;
    ctx->data[60] = ctx->bitlen >> 24;
    ctx->data[59] = ctx->bitlen >> 32;
    ctx->data[58] = ctx->bitlen >> 40;
    ctx->data[57] = ctx->bitlen >> 48;
    ctx->data[56] = ctx->bitlen >> 56;
    sha256_transform(ctx, ctx->data);
    for (i = 0; i < 4; ++i) {
		hash[i]      = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4]  = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8]  = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
	}
    ctx->datalen = 0;
    ctx->bitlen = 0;
    return (1);
}