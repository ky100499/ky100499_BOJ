import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
A = list(map(int, input().split()))

s = deque()
ans = [0]*N

for i in reversed(range(N)):
    while s and s[-1] <= A[i]:
        s.pop()
    ans[i] = s[-1] if s else -1
    s.append(A[i])
print(*ans)
