# Usage
# C/C++
## SHA-1/256/384/512
```C/C++
#include <stdio.h>
#include <string.h>
#include <cryrepo/sha1/256/384/512.h>
int main() {
    char *message = "Hello, World!";
    char hash[SHA1/256/384/512_HASH_BSIZE];
    SHA1/256/384/512_CTX ctx;
    sha1/256/384/512_init(&ctx);
    sha1/256/384/512_update(&ctx, message, strlen(message));
    sha1/256/384/512_final(&ctx, hash);
    printf("SHA-1/256/384/512: ");
    for (int i = 0; i < SHA1/256/384/512_HASH_BSIZE; i++) {
        printf("%02x", (unsigned char)hash[i]);
    }
    printf("\n");
    return 0;
}
```


# Python
## SHA-1/256/384/512
```Python
from cryrepo.hash import shaXXX # XXX- replace with 1, 256, 384, or 512
message = b"Hello, World!"
hash = shaXXX(message)
print("SHAXXX", hash.hex())
```