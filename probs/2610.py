import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)

def union(x, y):
    px, py = find(x), find(y)

    if px < py:
        P[py] = px
        find(y)
    else:
        P[px] = py
        find(x)

def find(x):
    if P[x] == x:
        return x
    else:
        P[x] = find(P[x])
        return P[x]

N = int(input())
M = int(input())
G = [[INF]*(N+1) for _ in range(N+1)]
P = [i for i in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a][b] = G[b][a] = 1
    union(a, b)

for i in range(N+1):
    find(i)

groups = []
for p in set(P[1:]):
    groups.append(
        [i for i, v in enumerate(P) if v == p]
    )
print(len(groups))

ans = []
for g in groups:
    l = len(g)
    dist = [[INF]*l for _ in range(l)]
    for i in range(l):
        for j in range(l):
            dist[i][j] = G[g[i]][g[j]]

    for k in range(l):
        for i in range(l):
            for j in range(l):
                dist[i][j] = min(
                    dist[i][j],
                    dist[i][k] + dist[k][j]
                )

    m, a = INF, 0
    if l > 1:
        for i in range(l):
            s = max(dist[i][:i] + dist[i][i+1:])
            if s < m:
                m, a = s, i
    ans.append(g[a])

print(*sorted(ans), sep='\n')
