from collections import deque

N = int(input())

board = [[0]*N for _ in range(N)]
col = [0]*N
ans = 0
queens = deque()

def nqueen(line):
    global ans

    if line == N:
        ans += 1
        return

    for j in range(N):
        if col[j] == 1:
            continue
        for qi, qj in queens:
            di, dj = abs(qi-line), abs(qj-j)
            if dj == 0 or di == dj:
                break
        else:
            queens.append((line, j))
            col[j] = 1
            nqueen(line+1)
            col[j] = 0
            queens.pop()

nqueen(0)
print(ans)
