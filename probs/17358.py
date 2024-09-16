MOD = int(1e9)+7

N = int(input())
ans = 1
while N:
    ans = (ans * (N-1)) % MOD
    N -= 2
print(ans)
