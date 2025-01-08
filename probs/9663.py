def update(i, j, v):
    x, y = i+1, j
    while x < N:
        B[x][y] += v
        x += 1
    x, y = i+1, j+1
    while x < N and y < N:
        B[x][y] += v
        x += 1
        y += 1
    x, y = i+1, j-1
    while x < N and y >= 0:
        B[x][y] += v
        x += 1
        y -= 1

def bt(i):
    global ans

    if i == N:
        ans += 1
        return

    for j in range(N):
        if not B[i][j]:
            update(i, j, 1)
            bt(i+1)
            update(i, j, -1)

N = int(input())

B = [[0]*N for _ in range(N)]
ans = 0
bt(0)
print(ans)
