#include "../../include/sha256.h"
#include "../../include/sha512.h"
#include "../../include/sha384.h"
#include <string.h>
#include <stdio.h>

int main(void){
	//char *str = "abc"; // ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad - Success
	//char *str = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"; // 248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1 - Success
	char *str = "abc";
	size_t len = 3;
	SHA256_CTX ctx;
	uint8_t hash[SHA256_HASH_BSIZE];
    printf("SHA256\n");
	if (sha256_init(&ctx) != 1){
		printf("Error: sha256_init failed\n");
		return 1;
	}
	if (sha256_update(&ctx, (unsigned char *)str, strlen(str)) != 1){
		printf("Error: sha256_update failed\n");
		return 1;
	}
	if (sha256_final(&ctx, hash) != 1){
		printf("Error: sha256_final failed\n");
		return 1;
	}
	for (int i = 0; i < SHA256_HASH_BSIZE; i++){
		printf("%02x", hash[i]);
	}

    SHA512_CTX ctx512;
    uint8_t hash512[SHA512_HASH_BSIZE];
    printf("\nSHA512\n");
    if (sha512_init(&ctx512) != 1){
        printf("Error: sha512_init failed\n");
        return 1;
    }
    if (sha512_update(&ctx512, (unsigned char *)str, strlen(str)) != 1){
        printf("Error: sha512_update failed\n");
        return 1;
    }
    if (sha512_final(&ctx512, hash512) != 1){
        printf("Error: sha512_final failed\n");
        return 1;
    }
    for (int i = 0; i < SHA512_HASH_BSIZE; i++){
        printf("%02x", hash512[i]);
    }
    SHA384_CTX sha384Ctx;
    uint8_t hash384[SHA384_HASH_BSIZE];
    printf("\nSHA384\n");
    if (sha384_init(&sha384Ctx) != 1){
        printf("Error: sha384_init failed\n");
        return 1;
    }
    if (sha384_update(&sha384Ctx, (unsigned char *)str, strlen(str)) != 1){
        printf("Error: sha384_update failed\n");
        return 1;
    }
    if (sha384_final(&sha384Ctx, hash384) != 1){
        printf("Error: sha384_final failed\n");
        return 1;
    }
    for (int i = 0; i < SHA384_HASH_BSIZE; i++){
        printf("%02x", hash384[i]);
    }
	return 0;
}
//abc SHA512 ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f⏎
//abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn
//hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu // 8e959b75dae313da8cf4f72814fc143f8f7779c6eb9f7fa17299aeadb6889018501d289e4900f7e4331b99dec4b5433ac7d329eeb6dd26545e96e55b874be909⏎