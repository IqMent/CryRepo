//
// Created by iqment on 4/21/25.
//

#ifndef CRYREPO_SHA1_H
#define CRYREPO_SHA1_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define SHA1_HASH_BSIZE 20
#define SHA1_WORD 4;
#define SHA1_BLOCK_SIZE 64
/*
*   The following logical operators will be applied to words:
* a. Bitwise logical word operations
* X AND Y  =  bitwise logical "and" of  X and Y.
* X OR Y   =  bitwise logical "inclusive-or" of X and Y.
* X XOR Y  =  bitwise logical "exclusive-or" of X and Y.
* NOT X    =  bitwise logical "complement" of X
*/

#define LSHIFT (x, n) ((x) << (n))
#define RSHIFT (x, n) ((x) >> (n))
#define CIRCULAR_LEFT (x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define CIRCULAR_RIGHT (x, n) (((x) >> (n)) | ((x) << (32 - (n))))
//Functions for SHA-1 defining
#define F1(x, y, z) ((x & y) | (~x & z))// F1 is used for rounds 0-19
#define F2(x, y, z) (x ^ y ^ z)// F2 is used for rounds 20-39
#define F3(x, y, z) ((x & y) | (x & z) | (y & z))// F3 is used for rounds 40-59
#define F4(x, y, z) (x ^ y ^ z)// F4 is used for rounds 60-79

// The SHA-1 algorithm is defined in the following document:
// https://www.ietf.org/rfc/rfc3174.txt

/*
*       SHA-1 is used to compute a message digest for a message or data file
*   that is provided as input.  The message or data file should be
*   considered to be a bit string.  The length of the message is the
*   number of bits in the message (the empty message has length 0).  If
*   the number of bits in a message is a multiple of 8, for compactness
*   we can represent the message in hex.  The purpose of message padding
*   is to make the total length of a padded message a multiple of 512.
*   SHA-1 sequentially processes blocks of 512 bits when computing the
*   message digest.  The following specifies how this padding shall be
*   performed.  As a summary, a "1" followed by m "0"s followed by a 64-
*   bit integer are appended to the end of the message to produce a
*   padded message of length 512 * n.  The 64-bit integer is the length
*   of the original message.  The padded message is then processed by the
*   SHA-1 as n 512-bit blocks.
 */

const unsigned long long *CONSTANTS_WORDS[4] = {
    0x5A827999, // Constants for rounds 0-19
    0x6ED9EBA1, // Constants for rounds 20-39
    0x8F1BBCDC,
    0xCA62C1D6// Constants for rounds 40-59
};

const unsigned long long H0 = 0x67452301;
const unsigned long long H1 = 0xEFCDAB89;
const unsigned long long H2 = 0x98BADCFE;
const unsigned long long H3 = 0x10325476;
const unsigned long long H4 = 0xC3D2E1F0;


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
