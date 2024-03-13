import sys
input = sys.stdin.readline

from collections import deque

q = deque()
for _ in range(int(input())):
    n = int(input())
    if n == 0:
        q.pop()
    else:
        q.append(n)
print(sum(q))
