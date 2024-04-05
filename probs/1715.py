import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

pq = []
ans = 0
for _ in range(int(input())):
    heappush(pq, int(input()))
while len(pq) > 1:
    s = heappop(pq) + heappop(pq)
    ans += s
    heappush(pq, s)
print(ans)
