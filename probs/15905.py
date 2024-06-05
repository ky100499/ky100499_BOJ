import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

class P():
    def __init__(self, q, p):
        self.q = q
        self.p = p

    def __lt__(self, other):
        if self.q == other.q:
            return self.p < other.p
        else:
            return self.q > other.q

N = int(input())
pq = []
for _ in range(N):
    heappush(pq, P(*map(int, input().split())))

[heappop(pq) for _ in range(4)]
q = heappop(pq).q

cnt = 0
while pq:
    if heappop(pq).q == q:
        cnt += 1
print(cnt)
