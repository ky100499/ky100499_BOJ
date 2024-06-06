MOD = int(1e4)+7

N, K = map(int, input().split())

pt = [[0]*(N+1) for _ in range(N+1)]
pt[0][0] = 1
for i in range(1, N+1):
    pt[i][0] = 1
    for j in range(1, i+1):
        pt[i][j] = (pt[i-1][j-1] + pt[i-1][j]) % MOD
print(pt[N][K])
