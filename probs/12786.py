import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

mv = [
    lambda x: x,
    lambda x: x+1,
    lambda x: x*2 if x < 10 else 20,
    lambda x: x-1,
]

def dijkstra():
    pq = [(0, 0, 1)]
    while pq:
        t, i, h = heappop(pq)

        if i == N:
            return t

        needt = True
        for nh in set(map(lambda f: f(h), mv)):
            if nh in trees[i]:
                heappush(pq, (t, i+1, nh))
                needt = False
        if needt and t < K:
            for h in trees[i]:
                heappush(pq, (t+1, i+1, h))
    return -1

N = int(input())
K = int(input())
trees = []
for _ in range(N):
    _, *h = map(int, input().split())
    trees.append(h)

print(dijkstra())
