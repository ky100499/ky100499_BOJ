from collections import deque

N, K = map(int, input().split())
time = [1000000 for _ in range(200001)]
time[N] = 0

q = deque([N])
visited = {}
while K not in visited:
    p = q.popleft()
    if p in visited:
        continue
    visited[p] = 1

    if p > 0:
        time[p-1] = min(time[p-1], time[p] + 1)
        q.append(p-1)
    if p < 100000:
        time[p+1] = min(time[p+1], time[p] + 1)
        q.append(p+1)
    if 0 < p < 100000:
        time[p*2] = min(time[p*2], time[p] + 1)
        q.append(p*2)
print(time[K])
