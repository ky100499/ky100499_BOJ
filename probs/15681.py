import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def dfs(node):
    if visited[node]:
        return 0
    visited[node] = 1

    ret = 1
    for n in G[node]:
        ret += dfs(n)

    ans[node] = ret
    return ret

N, R, Q = map(int, input().split())

G = [[] for _ in range(N+1)]
for _ in range(N-1):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)

ans = [0]*(N+1)
visited = [0]*(N+1)
dfs(R)

for _ in range(Q):
    print(ans[int(input())])
