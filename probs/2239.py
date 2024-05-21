import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def check(i, j, k):
    bi, bj = (i//3) * 3, (j//3) * 3
    for x in range(9):
        if b[x][j] == k or b[i][x] == k or b[bi+x//3][bj+x%3] == k:
            return False
    return True

def bt(n):
    if n == cnt:
        for r in b:
            print(*r, sep='')
        exit(0)

    i, j = zeros[n]

    for k in range(1, 10):
        if check(i, j, k):
            b[i][j] = k
            bt(n+1)
            b[i][j] = 0

b = [list(map(int, input().strip())) for _ in range(9)]
zeros = []
cnt = 0
for i in range(9):
    for j in range(9):
        if b[i][j] == 0:
            zeros.append((i, j))
            cnt += 1

bt(0)
