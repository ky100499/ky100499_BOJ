import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

N = int(input())
M = int(input())

dist = [[INF]*(N+1) for _ in range(N+1)]
for i in range(N+1):
    dist[i][i] = 0
for _ in range(M):
    a, b, c = map(int, input().split())
    dist[a][b] = min(dist[a][b], c)

route = [[[] for _ in range(N+1)] for _ in range(N+1)]

for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if dist[i][j] > dist[i][k]+dist[k][j]:
                dist[i][j] = dist[i][k]+dist[k][j]
                route[i][j] = route[i][k]+[k]+route[k][j]

for d in dist[1:]:
    print(*map(lambda x: 0 if x == INF else x, d[1:]))

for i in range(1, N+1):
    for j in range(1, N+1):
        if i == j:
            print(0)
        elif dist[i][j] == INF:
            print(0)
        else:
            print(len(route[i][j])+2, i, *route[i][j], j)
