import sha256
def test():
    arg = 'abc'
    print(f"arg: {arg}")
    print(f"sha256: {sha256.sha256(arg.encode()).hex()}")

if __name__ == "__main__":
    test()
