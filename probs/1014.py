import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def count(n, l):
    cnt = 0
    for i in range(l):
        cnt += (n >> i) & 1
    return cnt

for _ in range(int(input())):
    N, M = map(int, input().split())
    C = [0]*N
    for i in range(N):
        for j, c in enumerate(input().strip()):
            if c == 'x':
                C[i] += 1 << (M-j-1)

    dp = [[0]*(1<<M) for _ in range(N)]

    for i in range(1<<M):
        if i & (~C[0]) == i and i & (i<<1) == 0 and i & (i>>1) == 0:
            dp[0][i] = count(i, M)

    for i in range(1, N):
        for j in range(1<<M):
            c = count(j, M)
            for k in range(1<<M):
                if j & (~C[i]) == j and j & (j<<1) == 0 and j & (j>>1) == 0 and dp[i-1][k] != 0 and k & (j<<1) == 0 and k & (j>>1) == 0:
                    dp[i][j] = max(dp[i][j], dp[i-1][k]+c)

    print(max(dp[-1]))
