import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

T = int(input())

def dfs(b, w, h, x, y):
    if x + 1 < w and b[y][x+1] == 1:
        b[y][x+1] = 2
        dfs(b, w, h, x+1, y)
    if y + 1 < h and b[y+1][x] == 1:
        b[y+1][x] = 2
        dfs(b, w, h, x, y+1)
    if x - 1 >= 0 and b[y][x-1] == 1:
        b[y][x-1] = 2
        dfs(b, w, h, x-1, y)
    if y - 1 >= 0 and b[y-1][x] == 1:
        b[y-1][x] = 2
        dfs(b, w, h, x, y-1)

for _ in range(T):
    M, N, K = map(int, input().split())

    b = [[0 for _ in range(M)] for _ in range(N)]

    for _ in range(K):
        x, y = map(int, input().split())
        b[y][x] = 1

    cnt = 0
    for y in range(N):
        for x in range(M):
            if b[y][x] == 1:
                b[y][x] = 2
                dfs(b, M, N, x, y)
                cnt += 1
    print(cnt)
