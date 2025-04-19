// Author: iqMent
// Copyright: GNU Public
// Description: SHA256 implementation
// Date: 19/04/2025

#include "../../../include/sha512.h"
//Documentation: https://csrc.nist.gov/files/pubs/fips/180-2/final/docs/fips180-2.pdf

/*
 * The rotate right (circular right shift) operation ROTR n(x), where x is a w-bit word
 * and n is an integer with 0 £ n < w, is defined by
 * ROTRn(x) = (x >> n) v (x << w - n).
 * Thus, ROTR n(x) is equivalent to a circular shift (rotation) of x by n positions to the
 * right.
 */
#define ROT_R(x, n) ((x >> n) | (x << (64 - n)))
/*
 * The right shift operation SHR n(x), where x is a w-bit word and n is an integer with 0
 * £ n < w, is defined by SHR n(x) = x >> n.
*/
#define SHR(x, n) (x >> n)
/*
 * SHA512 - Function's Definitions
*/

#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

//Big sigma function's
#define SIGMA0(x) (ROT_R(x, 28) ^ ROT_R(x, 34) ^ ROT_R(x, 39))
#define SIGMA1(x) (ROT_R(x, 14) ^ ROT_R(x, 18) ^ ROT_R(x, 41))
//Small sigma function's
#define sigma0(x) (ROT_R(x, 1) ^ ROT_R(x, 8) ^ SHR(x, 7))
#define sigma1(x) (ROT_R(x, 19) ^ ROT_R(x, 61) ^ SHR(x, 6))

typedef unsigned char   byte;
typedef unsigned int    word; // 4 bytes

//Constants
static const unsigned long long SHA512_INITIAL_HASH_CONSTANTS[8] = {
        0x6a09e667f3bcc908,0xbb67ae8584caa73b,
        0x3c6ef372fe94f82b,0xa54ff53a5f1d36f1,
        0x510e527fade682d1,0x9b05688c2b3e6c1f,
        0x1f83d9abfb41bd6b,0x5be0cd19137e2179
};

static const unsigned long long SHA512_CONSTANTS[80] = {
        0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

static void sha512_transform(SHA512_CTX *ctx, const unsigned char data[])
{

    return ;
}

int sha512_init(SHA512_CTX *ctx){ // 1 - success, 0 - fail
    if (!ctx)
        return (0);
    ctx->bitlen=0;
    ctx->datalen = 0;
    ctx->state[0] = SHA512_INITIAL_HASH_CONSTANTS[0];
    ctx->state[1] = SHA512_INITIAL_HASH_CONSTANTS[1];
    ctx->state[2] = SHA512_INITIAL_HASH_CONSTANTS[2];
    ctx->state[3] = SHA512_INITIAL_HASH_CONSTANTS[3];
    ctx->state[4] = SHA512_INITIAL_HASH_CONSTANTS[4];
    ctx->state[5] = SHA512_INITIAL_HASH_CONSTANTS[5];
    ctx->state[6] = SHA512_INITIAL_HASH_CONSTANTS[6];
    ctx->state[7] = SHA512_INITIAL_HASH_CONSTANTS[7];
    return (1);
}

int sha512_update(SHA512_CTX *ctx, const unsigned char *data, const size_t len)
{
    if (!ctx || !data || len <= 0)
        return (0);
    word i;
    i = ctx->datalen;
    for (; i < len; i++){
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if (ctx->datalen == 128){
            //TODO sha512_transform(ctx, ctx->data);
            ctx->bitlen += 1024;
            ctx->datalen = 0;
        }
    }
    return (1);
}

int sha512_final(SHA512_CTX *ctx, unsigned char hash[])
{
    if (!ctx || !hash)
        return (0);

    return (1);
}
