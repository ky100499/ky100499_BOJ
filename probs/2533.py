import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def solve(cur, pre, early):
    if dp[cur][early] < N+1:
        return dp[cur][early]
    dp[cur][early] = early

    for nxt in G[cur]:
        if nxt == pre:
            continue

        if early:
            dp[cur][early] += min(
                solve(nxt, cur, 0),
                solve(nxt, cur, 1),
            )
        else:
            dp[cur][early] += solve(nxt, cur, 1)

    return dp[cur][early]

N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N-1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)

dp = [[N+1]*2 for _ in range(N+1)]
solve(1, 0, 0)
solve(1, 0, 1)
print(min(dp[1]))
