import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from itertools import permutations as p

def dfs(fruits, pos, depth, visited, num):
    if depth == 3:
        return (num, [pos])

    visited.add(pos)
    x, y = pos

    res = (0, [])
    mv = [[-1, 0], [0, -1], [1, 0], [0, 1]]
    for dx, dy in mv:
        nx, ny = x+dx, y+dy
        if (nx, ny) not in visited and 0<=nx<n and 0<=ny<n:
            tmp = fruits[nx][ny]
            fruits[nx][ny] = 0
            res = max(
                res,
                dfs(fruits, (nx, ny), depth+1, visited, num+tmp)
            )
            fruits[nx][ny] = tmp

    visited.remove(pos)
    return (fruits[x][y]+res[0], [pos]+res[1])

n, m = map(int, input().split())
fruits = [list(map(int, input().split())) for _ in range(n)]
pos = []
for _ in range(m):
    x, y = map(int, input().split())
    pos.append((x-1, y-1))

ans = 0
for orders in p(range(m), m):
    zeros = []
    originals = []
    s = 0
    for order in orders:
        res = dfs(fruits, pos[order], 0, set(), 0)
        s += res[0]
        for x, y in res[1]:
            zeros.append((x, y))
            originals.append(fruits[x][y])
            fruits[x][y] = 0
    ans = max(ans, s)
    for i, (x, y) in enumerate(zeros):
        fruits[x][y] = originals[i]
print(ans)
