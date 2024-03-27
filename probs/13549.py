from heapq import heappush, heappop

N, K = map(int, input().split())

pq = [(0, N)]
visited = [0]*100001
while pq:
    t, x = heappop(pq)
    if visited[x]:
        continue
    visited[x] = 1

    if x == K:
        print(t)
        break

    if x > 0 and visited[x-1] == 0:
        heappush(pq, (t+1, x-1))
    if x < 100000 and visited[x+1] == 0:
        heappush(pq, (t+1, x+1))
    if x < 50001 and visited[x*2] == 0:
        heappush(pq, (t, x*2))
