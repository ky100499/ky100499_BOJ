import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
q = deque()
for i, h in enumerate(map(int, input().split())):
    while q and q[-1][0] < h:
        q.pop()
    print(q[-1][1] if q else 0, end=' ')
    q.append((h, i+1))
print()
