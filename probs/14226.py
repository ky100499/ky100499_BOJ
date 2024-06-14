from collections import deque

INF = int(1e7)

S = int(input())

dp = [[INF]*S for _ in range(2*S)]
dp[1][0] = 0

q = deque([(0, 1, 0)])
while q:
    t, n, c = q.popleft()

    if dp[n][c] < t:
        continue

    if n == S:
        print(t)
        break

    if n-1 > 0 and dp[n-1][c] > t+1:
        dp[n-1][c] = t+1
        q.append((t+1, n-1, c))
    if n < S and dp[n][n] > t+1:
        dp[n][n] = t+1
        q.append((t+1, n, n))
    if c > 0 and n+c < 2*S and dp[n+c][c] > t+1:
        dp[n+c][c] = t+1
        q.append((t+1, n+c, c))
