# Crypto Repository
#### This repository contains the implementation of various cryptographic algorithms and protocols in C.
#### Author: iqMent

# CryRepo

is a cryptographic primitives library designed for rapid development and prototyping of blockchain projects.

It provides the necessary tools for implementing basic cryptographic functions, simplifying the creation and testing of new solutions.

CryRepo is focused on ease of use and speeding up the development process, allowing for quick integration of cryptography into blockchain applications at various stages of their creation.

# How to Install

# Mac/Linux
### 1. Clone the repository
```bash
git clone git@github.com:IqMent/CryRepo.git && cd CryRepo
```
### 2. Install (as a dynamic library)
```bash
make all
sudo make install
```
#### it will install in `/usr/local/lib` and `/usr/local/include`

### 3. Clean up
```bash
make clean
```
# Windows
### Coming Soon
# Uninstall
## Mac/Linux
```bash
sudo make uninstall
```
## Windows
### Coming Soon

# Usage
# C/C++
## SHA-1/256/384/512
```C/C++
#include <stdio.h>
#include <string.h>
#include <cryrepo/shaXXX.h> // XXX - replace with 1, 256, 384, or 512
int main() {
    char *message = "Hello, World!";
    char hash[SHAXXX_HASH_BSIZE];
    SHAXXX_CTX ctx;
    shaXXX_init(&ctx);
    shaXXX_update(&ctx, message, strlen(message));
    shaXXX_final(&ctx, hash);
    printf("SHA-XXX: ");
    for (int i = 0; i < SHAXXX_HASH_BSIZE; i++) {
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

# References
#### For SHA - family:
- [FIPS PUB 180-2 - Secure Hash Standard](https://csrc.nist.gov/files/pubs/fips/180-2/final/docs/fips180-2.pdf)
#### For BLAKE
- [BLAKE2B](https://datatracker.ietf.org/doc/html/rfc7693)
#### FOR ECDSA
- [ECDSA](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.186-4.pdf)
#### For RSA
- [RSA](https://datatracker.ietf.org/doc/html/rfc8017)
