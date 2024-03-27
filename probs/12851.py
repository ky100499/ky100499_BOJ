from collections import deque

N, K = map(int, input().split())

q = deque([(N, 0)])
ans_t, ans_n = 10**8, 0
visited = [0] * 100001
while q:
    x, t = q.popleft()
    visited[x] = 1
    if t > ans_t:
        break
    elif x == K:
        ans_t = t
        ans_n += 1
    else:
        if x > 0 and visited[x-1] == 0:
            q.append((x-1, t+1))
        if x < 100000 and visited[x+1] == 0:
            q.append((x+1, t+1))
        if x < 50001 and visited[x*2] == 0:
            q.append((x*2, t+1))
print(ans_t, ans_n, sep='\n')
