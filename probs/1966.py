import sys
input = sys.stdin.readline

from collections import deque

for _ in range(int(input())):
    N, M = map(int, input().split())
    idx = deque(range(N))
    q = deque(map(int, input().split()))

    cnt = 0
    while len(q):
        i, v = idx.popleft(), q.popleft()
        if len(q) == 0 or v >= max(q):
            cnt += 1
            if i == M:
                print(cnt)
                break
        else:
            idx.append(i)
            q.append(v)
