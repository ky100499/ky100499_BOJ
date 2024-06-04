from collections import deque

def hist(n):
    if n != -1:
        hist(dp[n][1])
        print(n, end=' ')

N = int(input())
dp = [(int(1e7), -1)]*(N+1)
dp[N] = (0, -1)

q = deque([N])
while q:
    n = q.popleft()
    cnt = dp[n][0]

    if n == 1:
        print(cnt)
        break

    if n % 3 == 0 and dp[n//3][0] > cnt+1:
        dp[n//3] = (cnt+1, n)
        q.append(n//3)
    if n % 2 == 0 and dp[n//2][0] > cnt+1:
        dp[n//2] = (cnt+1, n)
        q.append(n//2)
    if n > 1 and dp[n-1][0] > cnt+1:
        dp[n-1] = (cnt+1, n)
        q.append(n-1)

hist(1)
print()
