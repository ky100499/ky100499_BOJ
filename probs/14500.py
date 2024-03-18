import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(b, i, j, n, visited):
    if n == 4:
        return 0

    visited.append((i, j))

    cand = []

    if i > 0 and (i-1, j) not in visited:
        cand.append(dfs(b, i-1, j, n+1, visited[:]))
    if j > 0 and (i, j-1) not in visited:
        cand.append(dfs(b, i, j-1, n+1, visited[:]))
    if i < N-1 and (i+1, j) not in visited:
        cand.append(dfs(b, i+1, j, n+1, visited[:]))
    if j < M-1 and (i, j+1) not in visited:
        cand.append(dfs(b, i, j+1, n+1, visited[:]))

    return b[i][j] + (max(cand) if cand else 0)

N, M = map(int, input().split())

shapes = [
    [
        [1, 1, 1],
        [0, 1, 0],
    ],
    [
        [1, 0],
        [1, 1],
        [1, 0],
    ],
    [
        [0, 1, 0],
        [1, 1, 1],
    ],
    [
        [0, 1],
        [1, 1],
        [0, 1],
    ],
]

b = []
for _ in range(N):
    b.append(list(map(int, input().split())))

ans = 0
for i, j in [(i, j) for i in range(N) for j in range(M)]:
    ans = max(ans, dfs(b, i, j, 0, []))

for shape in shapes:
    for i in range(N-len(shape)+1):
        for j in range(M-len(shape[0])+1):
            s = 0
            for x in range(len(shape)):
                for y in range(len(shape[0])):
                    s += b[i+x][j+y] if shape[x][y] else 0
            ans = max(ans, s)
print(ans)
