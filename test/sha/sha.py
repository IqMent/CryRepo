from cryrepo.hash import sha384, sha512, sha256

print(sha256("abc".encode()).hex())
print(sha384("abc".encode()).hex())
print(sha512("abc".encode()).hex())