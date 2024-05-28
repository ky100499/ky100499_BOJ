import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

N = int(input())

dist = [[INF]*(N+1) for _ in range(N+1)]
for i in range(N+1):
    dist[i][i] = 0
while True:
    a, b = map(int, input().split())
    if a == b == -1:
        break
    dist[a][b] = 1
    dist[b][a] = 1

for i in range(1, N+1):
    for j in range(1, N+1):
        for k in range(1, N+1):
            dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k])

p = INF
ans = []
for i in range(1, N+1):
    pp = max(dist[i][1:])
    if p == pp:
        ans.append(i)
    elif p > pp:
        p = pp
        ans = [i]

print(p, len(ans))
print(*ans)
