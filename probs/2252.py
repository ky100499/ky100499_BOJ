import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())

idg = [0]*(N+1)
nxt = [[] for _ in range(N+1)]

for _ in range(M):
    A, B = map(int, input().split())
    idg[B] += 1
    nxt[A].append(B)

q = deque()
for i in range(1, N+1):
    if idg[i] == 0:
        q.append(i)

while q:
    n = q.popleft()
    print(n, end=' ')

    for m in nxt[n]:
        idg[m] -= 1
        if idg[m] == 0:
            q.append(m)
print()
