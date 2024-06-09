import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(s):
    # dist[i][j] -> i 지점까지 j원 쓰고 도착한 시간
    dist = [[INF]*(M+1) for _ in range(N+1)]
    dist[s][0] = 0

    pq = [(0, s, 0)]
    while pq:
        sd, s, sf = heappop(pq)

        if dist[s][sf] < sd:
            continue

        for t, td, f in edges[s]:
            if sf+f <= M and dist[t][sf+f] > dist[s][sf]+td and dist[s][sf]+td <= T:
                dist[t][sf+f] = dist[s][sf]+td
                heappush(pq, (dist[t][sf+f], t, sf+f))

    return dist

N = int(input())
T, M = map(int, input().split())

edges = [[] for _ in range(N+1)]
for _ in range(int(input())):
    u, v, w, m = map(int, input().split())
    edges[u].append((v, w, m))
    edges[v].append((u, w, m))

ans = INF
for f, t in enumerate(dijkstra(1)[N]):
    if t <= T:
        ans = min(ans, f)
print(-1 if ans == INF else ans)
