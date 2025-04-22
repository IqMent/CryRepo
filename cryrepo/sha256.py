import ctypes
from ctypes import c_uint8, c_size_t, c_uint32, c_uint64, c_void_p, POINTER

cryrepo_lib = ctypes.CDLL("/usr/local/lib/CryRepo.so")

class SHA256_CTX(ctypes.Structure):
    _fields_ = [
        ('data', ctypes.c_uint8 * 64),
        ('datalen', c_size_t),
        ('bitlen', c_uint64),
        ('state', c_uint32 * 8)
    ]
cryrepo_lib.sha256_init.argtypes = [POINTER(SHA256_CTX)]
cryrepo_lib.sha256_init.restype = ctypes.c_int

cryrepo_lib.sha256_update.argtypes = [POINTER(SHA256_CTX), POINTER(c_uint8), c_size_t]
cryrepo_lib.sha256_update.restype = ctypes.c_int

cryrepo_lib.sha256_final.argtypes = [POINTER(SHA256_CTX), POINTER(c_uint8)]
cryrepo_lib.sha256_final.restype = ctypes.c_int

def sha256_init():
    ctx = SHA256_CTX()
    ctx.datalen = 0
    ctx.bitlen = 0
    ctx.state = (c_uint32 * 8)()
    cryrepo_lib.sha256_init(ctypes.byref(ctx))
    return ctx

def sha256_update(ctx, data):
    data_len = len(data)
    data_array = (c_uint8 * data_len)(*data)
    cryrepo_lib.sha256_update(ctypes.byref(ctx), data_array, data_len)

def sha256_final(ctx):
    hash_array = (c_uint8 * 32)()
    cryrepo_lib.sha256_final(ctypes.byref(ctx), hash_array)
    return bytes(hash_array)

def sha256(data):
    ctx = sha256_init()
    sha256_update(ctx, data)
    return sha256_final(ctx)
