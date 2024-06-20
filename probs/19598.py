import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N = int(input())
A = sorted([tuple(map(int, input().split())) for _ in range(N)])

pq = []
ans = 0
for s, e in A:
    while pq and pq[0] <= s:
        heappop(pq)
    heappush(pq, e)
    ans = max(ans, len(pq))
print(ans)
