import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def bt(curr, d):
    visited[curr] = 1
    if visited.count(0) == 0:
        global ans
        ans = min(ans, d)
    else:
        for i, v in enumerate(visited):
            if not v:
                visited[i] = 1
                bt(i, d+dist[curr][i])
                visited[i] = 0

N, K = map(int, input().split())
dist = [list(map(int, input().split())) for _ in range(N)]

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

ans = 10**8
visited = [0]*N
bt(K, 0)
print(ans)
