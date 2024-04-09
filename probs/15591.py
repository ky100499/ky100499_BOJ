import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(s, k, depth=1):
    # 내려가면서 k 이하이면 return depth

N, Q = map(int, input().split())
edges = [[] for _ in range(N+1)]
for _ in range(N-1):
    p, q, r = map(int, input().split())
    edges[p].append((q, r))
    edges[q].append((p, r))

for _ in range(Q):
    k, v = map(int, input().split())
    print(dfs(v, k))
