import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

INF = int(1e10)

N, Q = map(int, input().split())
dist = [[INF]*(N+1) for _ in range(N+1)]
for _ in range(N-1):
    p, q, r = map(int, input().split())
    dist[p][q] = r
    dist[q][p] = r

print(*dist, sep='\n')

for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(i+1, N+1):
            if dist[i][k] != INF and dist[k][j] != INF:
                dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k], dist[k][j])

print(*dist, sep='\n')

for _ in range(Q):
    k, v = map(int, input().split())
    print(dist[v])
