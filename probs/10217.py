import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

INF = int(1e9)

for _ in range(int(input())):
    N, M, K = map(int, input().split())
    G = [[[] for _ in range(N+1)] for _ in range(N+1)]
    for _ in range(K):
        u, v, c, d = map(int, input().split())
        for ud, uc in G[u][v]:
            if c >= uc and d >= ud:
                break
        else:
            G[u][v].append((d, c))
    for i in range(N+1):
        for j in range(N+1):
            G[i][j].sort()

    dist = [[INF]*(M+1) for _ in range(N+1)]
    dist[1] = [0]*(M+1)
    q = deque([(0, 0, 1)])
    while q:
        d, c, s = q.popleft()

        if dist[s][c] < d:
            continue

        for t, ti in enumerate(G[s]):
            for td, tc in ti:
                nc, nd = c+tc, d+td
                if nc <= M and nd < dist[t][nc]:
                    for i in range(nc, M+1):
                        if dist[t][i] <= nd:
                            break
                        dist[t][i] = nd
                    q.append((nd, nc, t))
    print('Poor KCM' if dist[-1][-1] == INF else dist[-1][-1])
