from cryrepo.hash import sha256, sha384, sha512

print(sha256(b"abc").hex())
print(sha384(b"abc").hex())
print(sha512(b"abc").hex())