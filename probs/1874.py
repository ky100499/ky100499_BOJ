import sys
input = sys.stdin.readline

from collections import deque

n = int(input())

q, i, ops = deque(), 1, []
for _ in range(n):
    ipt = int(input())
    while i <= ipt:
        ops.append('+')
        q.append(i)
        i += 1
    if q.pop() != ipt:
        print('NO')
        break
    ops.append('-')
else:
    print('\n'.join(ops))
