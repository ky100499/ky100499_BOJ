import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
D = [list(input().rstrip()) for _ in range(N)]

B = [[0]*M for _ in range(N)]
ans, n = 0, 1
for i in range(N):
    for j in range(M):
        if B[i][j] == 0:
            x, y = i, j
            while True:
                if B[x][y] == 0:
                    B[x][y] = n
                    if D[x][y] == 'D':
                        x += 1
                    elif D[x][y] == 'U':
                        x -= 1
                    elif D[x][y] == 'R':
                        y += 1
                    elif D[x][y] == 'L':
                        y -= 1
                else:
                    if B[x][y] == n:
                        ans += 1
                    break
            n += 1
print(ans)
