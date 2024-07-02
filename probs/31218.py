import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M, Q = map(int, input().split())
B = [[0]*M for _ in range(N)]
cnt = N*M

for _ in range(Q):
    q, *p = map(int, input().split())

    if q == 1:
        dx, dy, x, y = p
        while 0 < x <= N and 0 < y <= M and not B[x-1][y-1]:
            B[x-1][y-1] = 1
            cnt -= 1
            x += dx
            y += dy
    elif q == 2:
        x, y = p
        print(B[x-1][y-1])
    else:
        print(cnt)
