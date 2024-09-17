import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N, K = map(int, input().split())
J = sorted([tuple(map(int, input().split())) for _ in range(N)])
C = sorted([int(input()) for _ in range(K)])

pq, j, ans = [], 0, 0
for i in range(K):
    while j < N and J[j][0] <= C[i]:
        heappush(pq, -J[j][1])
        j += 1
    if pq:
        ans -= heappop(pq)

print(ans)
