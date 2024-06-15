import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

MOD = int(1e9)+7

def power(n, p):
    if p == 1:
        return n

    x = power(n, p//2)
    if p%2:
        return (x*x*n) % MOD
    else:
        return (x*x) % MOD

N, K = map(int, input().split())

fact = [1]*(N+1)
for i in range(2, N+1):
    fact[i] = (i*fact[i-1]) % MOD

print((fact[N] * power(fact[N-K], MOD-2) * power(fact[K], MOD-2)) % MOD)
