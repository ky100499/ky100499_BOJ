import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
p = [list(map(int, input().split())) for _ in range(N)]

dist = [[0]*N for _ in range(N)]

for i in range(N-1):
    for j in range(i+1, N):
        dist[i][j] = (p[i][0]-p[j][0])**2 + (p[i][1]-p[j][1])**2
        dist[j][i] = dist[i][j]

cnt = 0
for i in range(N):
    for j in range(N-1):
        if i == j:
            continue
        for k in range(j+1, N):
            if i == k:
                continue
            if dist[i][j] + dist[i][k] == dist[j][k]:
                cnt += 1
print(cnt)
