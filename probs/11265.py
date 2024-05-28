import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())

dist = [[0]*(N+1)]
for _ in range(N):
    dist.append([0]+list(map(int, input().split())))

for i in range(1, N+1):
    for j in range(1, N+1):
        for k in range(1, N+1):
            dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k])

for _ in range(M):
    a, b, c = map(int, input().split())
    if dist[a][b] > c:
        print('Stay here')
    else:
        print('Enjoy other party')
