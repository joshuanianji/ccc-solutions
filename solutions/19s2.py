primes = [2, 3]


def isprime(n):
    for p in primes:
        if i % p == 0:
            return False

        if p * p > i:
            return True

    return True


for i in range(5, 2000000):
    if isprime(i):
        primes.append(i)


sp = set(primes)
t = int(input())

for _ in range(t):
    n = int(input())
    for i in range(n, 1, -1):
        if i in sp and 2 * n - i in sp:
            print(i, 2 * n - i)
            break