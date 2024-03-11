def isPrime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

M, N = map(int, input().split())
print('\n'.join(map(str, [x for x in range(max(2, M), N+1) if isPrime(x)])))
