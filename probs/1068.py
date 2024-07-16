import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(n):
    cnt = 0
    for i, p in enumerate(P):
        if p == n:
            cnt += dfs(i)
    if cnt == 0:
        cnt = 1
    dp[n] = cnt
    return cnt

N = int(input())
P = list(map(int, input().split()))
D = int(input())

root = P.index(-1)
dp = [0]*N
dfs(root)

print(dp[root] - dp[D] + (P[D] != -1 and dp[P[D]] == dp[D]))
