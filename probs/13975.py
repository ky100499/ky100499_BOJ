import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop, heapify

for _ in range(int(input())):
    K = int(input())
    pq = list(map(int, input().split()))
    heapify(pq)

    cost = 0
    while len(pq) > 1:
        s = heappop(pq) + heappop(pq)
        cost += s
        heappush(pq, s)
    print(cost)
