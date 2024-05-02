from collections import deque

N, K = map(int, input().split())

mv = [
    lambda x: x-1,
    lambda x: x+1,
    lambda x: x*2,
]

q = deque([(N, 0, -1)])
visited = [0]*100001
prev = [-1]*100001
while q:
    n, t, p = q.popleft()
    if visited[n]:
        continue
    visited[n] = 1
    prev[n] = p
    if n == K:
        print(t)
        break

    for f in mv:
        nn = f(n)
        if 0 <= nn <= 100000 and not visited[nn]:
            q.append((nn, t+1, n))

ans = []
while K != -1:
    ans.append(K)
    K = prev[K]
print(*ans[::-1])
