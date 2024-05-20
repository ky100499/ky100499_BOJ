import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
A = list(map(int, input().split()))

s = deque()
ans = deque()

for a in reversed(A):
    while s:
        if s[-1] > a:
            ans.appendleft(s[-1])
            break
        s.pop()
    else:
        ans.appendleft(-1)

    s.append(a)
print(*ans)
