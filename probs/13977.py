import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

MOD = int(1e9)+7
MAX = int(4e6)

fact = [1]*(MAX+1)
for i in range(2, MAX+1):
    fact[i] = (i*fact[i-1]) % MOD

def power(n, p):
    if p == 1:
        return n

    x = power(n, p//2)
    if p%2:
        return (x*x*n) % MOD
    else:
        return (x*x) % MOD

for _ in range(int(input())):
    N, K = map(int, input().split())
    print((fact[N] * power(fact[N-K], MOD-2) * power(fact[K], MOD-2)) % MOD)
