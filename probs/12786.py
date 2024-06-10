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
    dist = [[INF]*21 for _ in range(N+1)]
    dist[0][1] = 0

    pq = [(0, 0, 1)]
    while pq:
        sd, s, h = heappop(pq)

        if dist[s][h] < sd:
            continue

        if s == N:
            return sd

        needt = True
        for nh in set(map(lambda f: f(h), mv)):
            if nh in trees[s] and dist[s+1][nh] > sd:
                dist[s+1][nh] = sd
                heappush(pq, (sd, s+1, nh))
                needt = False
        if needt and sd < K:
            for h in trees[s]:
                if dist[s+1][h] > sd+1:
                    dist[s+1][h] = sd+1
                    heappush(pq, (sd+1, s+1, h))
    return -1

N = int(input())
K = int(input())
trees = []
for _ in range(N):
    _, *h = map(int, input().split())
    trees.append(h)

print(dijkstra())
