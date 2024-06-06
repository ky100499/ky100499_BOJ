import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

N, M = map(int, input().split())

dist = [[INF]*(N+1) for _ in range(N+1)]
for i in range(N+1):
    dist[i][i] = 0
route = [[-1]*(N+1) for _ in range(N+1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    dist[a][b] = c
    dist[b][a] = c
    route[a][b] = b
    route[b][a] = a

for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]
                route[i][j] = route[i][k]

for i in range(1, N+1):
    for j in range(1, N+1):
        if i == j:
            print('- ', end='')
        elif route[i][j] != -1:
            print(f'{route[i][j]} ', end='')
        else:
            print(f'{j} ', end='')
    print()
