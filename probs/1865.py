import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = 10**8

for _ in range(int(input())):
    N, M, W = map(int, input().split())

    edges = [{} for _ in range(N+1)]
    for _ in range(M):
        s, e, t = map(int, input().split())
        if e in edges[s]:
            edges[s][e] = min(edges[s][e], t)
        else:
            edges[s][e] = t
        edges[e][s] = edges[s][e]
    for _ in range(W):
        s, e, t = map(int, input().split())
        if e in edges[s]:
            edges[s][e] = min(edges[s][e], -t)
        else:
            edges[s][e] = -t

    dist = [INF]*(N+1)
    dist[1] = 0
    for _ in range(N):
        update = False
        for i in range(1, N+1):
            for j, t in edges[i].items():
                if dist[j] > dist[i]+t:
                    update = True
                    dist[j] = dist[i]+t
        if not update:
            print('NO')
            break
    else:
        print('YES')
