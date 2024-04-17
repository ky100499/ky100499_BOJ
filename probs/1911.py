import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N, L = map(int, input().split())
pools = []
for _ in range(N):
    heappush(pools, list(map(int, input().split())))

cnt, s = 0, 0
for _ in range(N):
    a, b = heappop(pools)
    a = max(a, s)
    n = (b-a-1) // L + 1
    cnt += n
    s = a+n*L
print(cnt)
