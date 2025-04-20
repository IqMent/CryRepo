#include "../../include/sha256.h"
#include <string.h>
#include <stdio.h>
int main(void){
	//char *str = "abc"; // ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad - Success
	//char *str = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"; // 248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1 - Success
	char *str = "abc"; 
	size_t len = 3;
	SHA256_CTX ctx;
	uint8_t hash[SHA256_HASH_BSIZE];
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
	return 0;
}