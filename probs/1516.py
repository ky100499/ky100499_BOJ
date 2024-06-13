import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
T = [0]*(N+1)
pre = {i:[] for i in range(1, N+1)}
req = {i:[] for i in range(1, N+1)}
cnt = [0]*(N+1)
for i in range(1, N+1):
    t, *R = map(int, input().split())
    T[i] = t
    pre[i] = R[:-1]
    for r in R[:-1]:
        req[r].append(i)
    cnt[i] = len(R)-1

q = deque()
for i, v in enumerate(cnt):
    if i != 0 and v == 0:
        q.append(i)

ans = [0]*(N+1)

while q:
    n = q.popleft()
    cnt[n] = -1

    t = 0
    for p in pre[n]:
        t = max(t, ans[p])

    ans[n] = t+T[n]

    for r in req[n]:
        cnt[r] -= 1
        if cnt[r] == 0:
            q.append(r)
print(*ans[1:], sep='\n')
