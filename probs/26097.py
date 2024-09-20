import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
B = [[]]+[[-1]+list(map(int, input().split())) for _ in range(N)]

if N%2 & M%2:
    print(-1)
elif sum(map(lambda x: x.count(0), B)) % 2:
    print(-1)
else:
    ans = '1'
    cnt = N * M
    while cnt:
        elim = False
        for i in range(1, N+1):
            for j in range(1, M+1):
                if (n := B[i][j]) == -1:
                    continue

                q = deque([(i, j)])
                V = [[0]*(M+1) for _ in range(N+1)]
                while q:
                    x, y = q.popleft()

                    if V[x][y]:
                        continue
                    V[x][y] = 1

                    for dx, dy in ((-1,0),(0,-1),(1,0),(0,1)):
                        nx, ny = x+dx, y+dy
                        if 0 < nx <= N and 0 < ny <= M and not V[nx][ny]:
                            if B[nx][ny] == n:
                                ans += f'\n{i} {j} {nx} {ny}'
                                B[i][j] = B[nx][ny] = -1
                                cnt -= 2
                                elim = True
                                break
                            elif B[nx][ny] == -1:
                                q.append((nx, ny))
                    else:
                        continue
                    break
        if not elim:
            print(-1)
            break
    else:
        print(ans)
