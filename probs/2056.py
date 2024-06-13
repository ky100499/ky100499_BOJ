import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())

T = [0]*(N+1)
req = {i:[] for i in range(N+1)}
indeg = [0]*(N+1)

for i in range(1, N+1):
    t, n, *r = map(int, input().split())
    T[i] = t
    indeg[i] = n
    for j in r:
        req[j].append(i)

ans = [0]*(N+1)
q = deque()
for i, d in enumerate(indeg):
    if i != 0 and d == 0:
        q.append(i)

while q:
    n = q.popleft()
    ans[n] += T[n]

    for m in req[n]:
        ans[m] = max(ans[m], ans[n])
        indeg[m] -= 1
        if indeg[m] == 0:
            q.append(m)

print(max(ans))
