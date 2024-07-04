import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop, heapify

N, M, K = map(int, input().split())

Y = 0
pq = [-int(input()) for _ in range(N)]
heapify(pq)

days = 0
for p in pq:
    days += (-p-K-1) // M + 1
print(days)

while pq:
    p = -heappop(pq)
    if p > M+K:
        heappush(pq, -p+M)
    Y = Y//2+p
    print(Y)
