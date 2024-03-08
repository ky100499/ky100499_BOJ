import sys
input = sys.stdin.readline

from collections import deque

N, M = map(int, input().split())
output = list(map(int, input().split()))

q = deque([i + 1 for i in range(N)])

cnt = 0
for out in output:
    idx = q.index(out)
    if idx <= N // 2:
        cnt += idx
        q.rotate(-idx)
    else:
        cnt += N - idx
        q.rotate(N - idx)
    q.popleft()
    N -= 1
print(cnt)
