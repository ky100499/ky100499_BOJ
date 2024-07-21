import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(i, j, n, d):
    if d == 6:
        ans.add(n)
        return

    for di, dj in [[-1,0], [0,-1], [1,0], [0,1]]:
        ni, nj = i+di, j+dj
        if 0 <= ni < 5 and 0 <= nj < 5:
            dfs(ni, nj, 10*n+B[ni][nj], d+1)

B = [list(map(int, input().split())) for _ in range(5)]

ans = set()
for i in range(5):
    for j in range(5):
        dfs(i, j, B[i][j], 1)
print(len(ans))
