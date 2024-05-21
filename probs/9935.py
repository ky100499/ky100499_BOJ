import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

S = input().strip()
B = input().strip()

l = len(B)
q = deque()
for c in S:
    q.append(c)

    if len(q) >= l and q[-1] == B[-1]:
        i = l-1
        while i >= 0 and q[-1] == B[i]:
            q.pop()
            i -= 1
        if i != -1:
            q.extend(B[i+1:])
if q:
    print(*q, sep='')
else:
    print('FRULA')
