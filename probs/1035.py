import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

m = 0
for i in range(5):
    for j, c in enumerate(input().rstrip()):
        if c == '*':
            m |= 1 << (5*i + j)

q = deque([(m, 0)])
v = set()

while q:
    m, d = q.popleft()

    if m in v:
        continue
    v.add(m)

    tmp = m
    tq = deque()
    for i in range(25):
        if tmp & (1 << i):
            tq.append((i//5, i%5))
            break

    while tq:
        i, j = tq.popleft()

        if tmp & (1 << (5*i+j)) == 0:
            continue
        tmp ^= (1 << (5*i+j))

        for di, dj in [(-1,0), (0,-1), (1,0), (0,1)]:
            ni, nj = i+di, j+dj
            if 0 <= ni < 5 and 0 <= nj < 5 and tmp & (1 << (5*ni+nj)):
                tq.append((ni, nj))

    if tmp == 0:
        print(d)
        break

    for i in range(5):
        for j in range(5):
            if m & (1 << (5*i + j)):
                for di, dj in [(-1,0), (0,-1), (1,0), (0,1)]:
                    ni, nj = i+di, j+dj
                    if 0 <= ni < 5 and 0 <= nj < 5 and m & (1 << (5*ni+nj)) == 0:
                        nm = (m ^ (1 << (5*i+j))) | (1 << (5*ni+nj))
                        if nm not in v:
                            q.append((nm, d+1))
