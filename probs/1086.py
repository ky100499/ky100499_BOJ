import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def fact(n):
    return n*fact(n-1) if n > 1 else 1

N = int(input())
A = [input().rstrip() for _ in range(N)]
K = int(input())
R = list(map(lambda x: int(x)%K, A))
L = list(map(len, A))

dgt = [1]*51
for i in range(1, 51):
    dgt[i] = (dgt[i-1] * 10) % K

dp = [[0]*K for _ in range(1<<N)]
for i, r in enumerate(R):
    dp[1<<i][r] = 1
for i in range(1, 1<<N):
    for j in range(N):
        if i & (1<<j):
            for k in range(K):
                dp[i][(k*dgt[L[j]]+R[j])%K] += dp[i^(1<<j)][k]

if dp[-1][0]:
    t = fact(N)
    g = gcd(dp[-1][0], t)
    print(f'{dp[-1][0]//g}/{t//g}')
else:
    print('0/1')
