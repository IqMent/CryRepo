//
// Created by IqMent on 09.05.2025.
//

#ifndef CRYREPO_BIGINT_H
#define CRYREPO_BIGINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct s_BigNum {
    unsigned int *data;
    unsigned long long size;
    signed short sign;
} BNUM;

typedef enum {
    BNUM_ADD = 1,
    BNUM_SUB,
    BNUM_MUL,
    BNUM_DIV,
    BNUM_MOD
} BNUM_OP;

BNUM fromula(const char *formula, ...);

#ifdef __cplusplus
};
#endif

#endif //CRYREPO_BIGINT_H
