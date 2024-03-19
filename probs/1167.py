import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(node, visited):
    visited[node] = 1
    nxt = []
    for i, d in enumerate(edge[node]):
        if d and i not in visited:
            nxt.append((i, d))
    return max([
        d + dfs(i, visited) for i, d in nxt
    ])

V = int(input())
edge = [[0] * (V+1) for _ in range(V+1)]
for _ in range(V):
    ipt = list(map(int, input().split()))
    i = 1
    while ipt[i] != -1:
        edge[ipt[0]][ipt[i]] = ipt[i+1]
        i += 2
