import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N, M = map(int, input().split())
X = list(map(int, input().split()))

cnt, m, pq = 0, 0, []
for x in X:
    m += x
    heappush(pq, -x)
    while m >= M:
        m += 2*heappop(pq)
        cnt += 1
print(cnt)
