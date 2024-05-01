import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

INF = 10**12

def dijkstra(s):
    dist = [INF]*M
    dist[s] = 0

    bf = [-1]*M

    pq = [(0, s)]

    while pq:
        _, s = heappop(pq)

        for t, w in edges[s]:
            if dist[t] > dist[s]+w:
                dist[t] = dist[s]+w
                bf[t] = s
                heappush(pq, (dist[t], t))

    if dist[M-1] == INF:
        return -1
    else:
        ans = [M-1]
        i = M-1
        while bf[i] != -1:
            ans.append(bf[i])
            i = bf[i]
        return ' '.join(map(str, ans[::-1]))

for i in range(int(input())):
    N, M = map(int, input().split())
    edges = [[] for _ in range(M)]
    for _ in range(N):
        x, y, z = map(int, input().split())
        edges[x].append((y, z))
        edges[y].append((x, z))

    ans = dijkstra(0)
    print(f'Case #{i+1}: {ans}')
