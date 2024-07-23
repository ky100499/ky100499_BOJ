import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)

N = int(input())
dist = [[INF]*N for _ in range(N)]
for i in range(N):
    for j, v in enumerate(input().rstrip()):
        if v == 'Y':
            dist[i][j] = 1

for k in range(N):
    for i in range(N):
        for j in range(N):
            if i != j and dist[i][j] > dist[i][k]+dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

ans = 0
for i in range(N):
    ans = max(ans, len(list(filter(lambda x: x <= 2, dist[i]))))
print(ans)
