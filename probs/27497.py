import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

q = deque()
cmd = deque()

for _ in range(int(input())):
    ipt = input().split()
    n = int(ipt[0])

    if n == 1:
        q.append(ipt[1])
        cmd.append(1)
    elif n == 2:
        q.appendleft(ipt[1])
        cmd.append(2)
    elif q:
        c = cmd.pop()
        if c == 1:
            q.pop()
        else:
            q.popleft()

print(''.join(q) if q else 0)
