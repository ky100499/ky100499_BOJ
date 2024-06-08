import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+7

def power(n, p):
    if p == 1:
        return n % MOD
    else:
        x = power(n, p//2)
        if p % 2:
            return (x*x*n) % MOD
        else:
            return (x*x) % MOD

ans = 0
for i in range(int(input())):
    N, S = map(int, input().split())
    ans = (ans + S * power(N, MOD-2)) % MOD
print(ans)
