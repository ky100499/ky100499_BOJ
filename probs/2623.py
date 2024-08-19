import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, M = map(int, input().split())
P = [[] for _ in range(N+1)]
O = [0]*(N+1)
for _ in range(M):
    n, *ipt = map(int, input().split())
    for i in range(1, n):
        P[ipt[i-1]].append(ipt[i])
        O[ipt[i]] += 1

q = deque()
for i in range(1, N+1):
    if not O[i]:
        q.append(i)

ans = []
while q:
    x = q.popleft()
    ans.append(x)

    for y in P[x]:
        O[y] -= 1
        if O[y] == 0:
            q.append(y)

if len(ans) == N:
    print(*ans, sep='\n')
else:
    print(0)
