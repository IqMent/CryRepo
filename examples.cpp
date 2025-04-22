//
// Created by iqment on 4/22/25.
//

// SHA

#include <cryrepo/sha256.h>
#include "include/sha384.h"
#include "include/sha512.h"


#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>

void sha256_test(const unsigned char *data){
    SHA256_CTX ctx;
    unsigned char hash[32];
    if (sha256_init(&ctx) <= 0){
        std::cerr << "Error: sha256_init failed" << std::endl;
        return;
    }
    if (sha256_update(&ctx, data, 3) <= 0){
        std::cerr << "Error: sha256_update failed" << std::endl;
        return;
    }
    if (sha256_final(&ctx, hash) <= 0){
        std::cerr << "Error: sha256_final failed" << std::endl;
        return;
    }
    int i = 0;
    while (i < 32){
        printf("%02x", hash[i]);
        i++;
    }
}

void sha384_test(const unsigned char *data) {
    SHA384_CTX ctx;
    unsigned char hash[48];
    if (sha384_init(&ctx) <= 0) {
        std::cerr << "Error: sha384_init failed" << std::endl;
        return;
    }
    if (sha384_update(&ctx, data, 3) <= 0) {
        std::cerr << "Error: sha384_update failed" << std::endl;
        return;
    }
    if (sha384_final(&ctx, hash) <= 0) {
        std::cerr << "Error: sha384_final failed" << std::endl;
        return;
    }
    int i = 0;
    while (i < 48) {
        printf("%02x", hash[i]);
        i++;
    }
}

void sha512_test(const unsigned char *data) {
    SHA512_CTX ctx;
    unsigned char hash[64];
    if (sha512_init(&ctx) <= 0) {
        std::cerr << "Error: sha512_init failed" << std::endl;
        return;
    }
    if (sha512_update(&ctx, data, 3) <= 0) {
        std::cerr << "Error: sha512_update failed" << std::endl;
        return;
    }
    if (sha512_final(&ctx, hash) <= 0) {
        std::cerr << "Error: sha512_final failed" << std::endl;
        return;
    }
    int i = 0;
    while (i < 64) {
        printf("%02x", hash[i]);
        i++;
    }
}

int main(){
    const char *data = "abc";
    sha256_test((unsigned char *)data);
    std::cout << std::endl;
    sha384_test((unsigned char *)data);
    std::cout << std::endl;
    sha512_test((unsigned char *)data);
    return 1;
}