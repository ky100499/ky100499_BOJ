from collections import deque

N = int(input())
danji = []
for _ in range(N):
    danji.append(list(map(int, input())))

danji_cnt = 0
house_cnt = []
for i, j in [(i, j) for i in range(N) for j in range(N)]:
    if danji[i][j] == 1:
        danji_cnt += 1
        q = deque([(i, j)])
        house = 0
        while q:
            x, y = q.popleft()
            if danji[x][y] == 1:
                danji[x][y] = -1
                house += 1
                if x > 0:
                    q.append((x-1, y))
                if y > 0:
                    q.append((x, y-1))
                if x < N-1:
                    q.append((x+1, y))
                if y < N-1:
                    q.append((x, y+1))
        house_cnt.append(house)
print('\n'.join(map(str, [danji_cnt, *sorted(house_cnt)])))
