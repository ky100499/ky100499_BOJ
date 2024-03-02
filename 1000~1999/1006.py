import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

for i in range(T):
    N, W = map(int, input().split())

    enemies = []
    for _ in range(2):
        enemies.append(list(map(int, input().split())))


    def getIdx(row, col):
        if col < 0: col += N
        if col >= N: col -= N
        idx = row * N + col
        return idx

    killed = []
    cnt = 0

    enemies_flatten = enemies[0] + enemies[1]

    q = deque()
    q.append(enemies_flatten.index(max(enemies_flatten)))

    while len(q):
        idx = q.popleft()
        if idx in killed: continue

        r, c = idx // N, idx % N

        pt_next = [
            [r, c - 1],
            [r ^ 1, c],
            [r, c + 1]
        ]

        max_idx = None
        max_enemy = 0
        for pt in pt_next:
            idx_next = getIdx(*pt)
            pt = [idx_next // N, idx_next % N]
            if idx_next not in killed:
                q.append(idx_next)

                if enemies[r][c] + enemies[pt[0]][pt[1]] <= W \
                    and max_enemy < enemies[pt[0]][pt[1]]:
                        max_enemy = enemies[pt[0]][pt[1]]
                        max_idx = idx_next

        killed.append(idx)
        if max_enemy > 0:
            # print(idx+1, max_idx+1)
            killed.append(max_idx)
            cnt += 1

    print(2 * N - cnt)
