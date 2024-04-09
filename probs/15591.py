import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def dfs(s, k, visited, depth=0):
    visited.add(s)
    ret = 0
    for t, d in edges[s]:
        if d >= k and t not in visited:
            ret += dfs(t, k, visited, depth+1) - (depth if ret else 0)
    return ret if ret else depth

N, Q = map(int, input().split())
edges = [[] for _ in range(N+1)]
for _ in range(N-1):
    p, q, r = map(int, input().split())
    edges[p].append((q, r))
    edges[q].append((p, r))

for _ in range(Q):
    k, v = map(int, input().split())
    print(dfs(v, k, set()))
