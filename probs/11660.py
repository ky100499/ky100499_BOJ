import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
S = [[0]*(N+1) for _ in range(N+1)]
for i in range(N):
    ipt = list(map(int, input().split()))
    for j in range(N):
        S[i+1][j+1] = S[i+1][j] + S[i][j+1] - S[i][j] + ipt[j]

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    x1, y1 = x1-1, y1-1
    print(S[x2][y2] - S[x1][y2] - S[x2][y1] + S[x1][y1])
