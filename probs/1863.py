import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

q = deque()
cnt = 0
for _ in range(int(input())):
    _, h = map(int, input().split())

    while q and q[-1] > h:
        q.pop()

    if q and q[-1] == h:
        continue

    if h > 0:
        q.append(h)
        cnt += 1
print(cnt)
