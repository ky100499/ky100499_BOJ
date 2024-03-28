import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque
from heapq import heappush, heappop

class Shark():
    def __init__(self, x, y, t):
        self.x = x
        self.y = y
        self.t = t

    def __lt__(self, other):
        if self.t < other.t:
            return True
        elif self.t > other.t:
            return False
        elif self.x < other.x:
            return True
        elif self.x > other.x:
            return False
        elif self.y < other.y:
            return True
        else:
            return False

N = int(input())
aqua = [list(map(int, input().split())) for _ in range(N)]

sh = (0, 0)
for i, j in [(i, j) for i in range(N) for j in range(N)]:
    if aqua[i][j] == 9:
        aqua[i][j] = 0
        sh = (i, j)
        break

size, cnt = 2, 0
pq = [Shark(*sh, 0)]
visited = {}
max_t = 0
while pq:
    sh = heappop(pq)
    x, y = sh.x, sh.y
    if (x, y) in visited:
        continue
    visited[x, y] = 1

    if 0 < aqua[x][y] < size:
        aqua[x][y] = 0
        max_t = sh.t
        cnt += 1
        if cnt == size:
            size, cnt = size+1, 0
        pq = []
        visited = {(x, y): 1}

    for dx, dy in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
        nx, ny = x+dx, y+dy
        if 0 <= nx < N and 0 <= ny < N and aqua[nx][ny] <= size:
            heappush(pq, Shark(nx, ny, sh.t+1))

print(max_t)
