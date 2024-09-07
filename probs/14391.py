import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(i, j, p):
    if j == M:
        i, j = i+1, 0
    if i == N:
        return p

    if V[i][j]:
        return dfs(i, j+1, p)

    ret = 0

    np = 0
    for ni in range(i, N):
        if V[ni][j]:
            for ri in reversed(range(i, ni)):
                V[ri][j] = 0
            break
        np = 10*np + B[ni][j]
        V[ni][j] = 1
        ret = max(ret, dfs(i, j+1, p+np))
    else:
        for ri in reversed(range(i, N)):
            V[ri][j] = 0

    np = 0
    for nj in range(j, M):
        if V[i][nj]:
            for rj in reversed(range(j, nj)):
                V[i][rj] = 0
            break
        np = 10*np + B[i][nj]
        V[i][nj] = 1
        ret = max(ret, dfs(i, nj+1, p+np))
    else:
        for rj in reversed(range(j, M)):
            V[i][rj] = 0

    return ret

N, M = map(int, input().split())
B = [list(map(int, input().rstrip())) for _ in range(N)]
V = [[0]*M for _ in range(N)]
print(dfs(0, 0, 0))
