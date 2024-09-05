import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = int(1e9)

def bit_count(n):
    cnt = 0
    while n:
        cnt += n&1
        n >>= 1
    return cnt

N, K = map(int, input().split())
C = [0] + [int(input(), 2) for _ in range(N)]

codes = set(C[1:])

dist = {}
dist[C[1]] = 0
prev = [-1]*(N+1)
q = deque([1])
while q:
    i = q.popleft()
    for j in range(1, N+1):
        if i != j and bit_count(C[i]^C[j]) == 1 and dist[i]+1 < dist[j]:
            dist[j] = dist[i]+1
            prev[j] = i
            q.append(j)

for _ in range(int(input())):
    q = int(input())
    if prev[q] == -1:
        print(-1)
    else:
        ans = []
        while q != -1:
            ans.append(q)
            q = prev[q]
        print(*ans[::-1])
