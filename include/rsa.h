// Author: iqMent
// Copyright: GNU Public
// Description: RSA implementation
// Date: 12/05/2025

#ifndef RSA_H
#define RSA_H

# ifdef __cplusplus
extern "C" {
# endif

#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#ifndef RSA_BITLEN
# define RSA_BITLEN 2048
#endif

typedef struct {
    unsigned char *n; // modulus
    unsigned char *e; // public exponent
    unsigned char *d; // private exponent
    unsigned char *p; // prime 1
    unsigned char *q; // prime 2
    unsigned char *dp; // d mod (p-1)
    unsigned char *dq; // d mod (q-1)
    unsigned char *qinv; // q^-1 mod p
} RSA_KEYPAIR;

typedef struct {
    unsigned char *n; // modulus
    unsigned char *e; // public exponent
} RSA_PUBLIC_KEY;

typedef struct {
    unsigned char *n; // modulus
    unsigned char *d; // private exponent
} RSA_PRIVATE_KEY;

#ifndef DEFAULT_PATH
# ifdef _WIN32
#   define DEFAULT_PATH ""
# elif __linux__
#   define DEFAULT_PATH "/home/"
#       define DEFAULT_FINISH_PATH "/.crytmp/"
# elif __APPLE__
#   define DEFAULT_PATH "/Users/"
#       define DEFAULT_FINISH_PATH "/.crytmp/"
# endif
#endif

unsigned char *rsa_encrypt(const unsigned char *message, const unsigned char *key,
                           const size_t klen);
unsigned char *rsa_decrypt(const unsigned char *ciphertext, const unsigned char *key,
                           const size_t klen);
int rsa_generate_keypair(unsigned char *pkey, unsigned char *key,
                         const size_t klen);
void rsa_free_keypair(unsigned char *pkey, unsigned char *key);
int rsa_write_keypair(const char *path, const unsigned char *pkey,
                      const unsigned char *key,
                      const size_t klen);
int rsa_read_key(const unsigned char *path, unsigned char *key, const size_t klen);
int rsa_write_public_key(const char *path, const unsigned char *key,
                          const size_t klen);
int rsa_read_public_key(const char *path, unsigned char *key, const size_t klen);
int rsa_write_private_key(const char *path, const unsigned char *key,
                           const size_t klen);
int rsa_read_private_key(const char *path, unsigned char *key, const size_t klen);
int rsa_generate_keypair_file(const char *path, const unsigned char *pkey,
                               const unsigned char *key, const size_t klen);

# ifdef __cplusplus
}
# endif

#endif //RSA_H
