//
// Created by IqMent on 26.03.2025.
//

//#include "../include/sha256.h"
#include <assert.h>

#include <openssl/sha.h>
#include <stdio.h>
int main(void){
	SHA256_CTX ctx;
	unsigned char hash[SHA256_DIGEST_LENGTH];
	char *str = "Hello";
	SHA256_init(&ctx);
	SHA256_update(&ctx, str, 5);
	SHA256_final(&ctx, hash);
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		printf("%02x", hash[i]);
	}
    return 0;
}