import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
banned = [[0]*(N+1) for _ in range(N+1)]

for _ in range(M):
    a, b = sorted(map(int, input().split()))
    banned[a][b] = 1

cnt = 0
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if banned[i][j]:
            continue
        for k in range(j+1, N+1):
            if banned[i][k] or banned[j][k]:
                continue
            cnt += 1
print(cnt)
