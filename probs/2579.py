import sys
input = sys.stdin.readline

N = int(input())
points = []
for _ in range(N):
    points.append(int(input()))

if N == 1:
    print(points[0])
else:
    dp = [0 for _ in range(N)]
    dp[0] = (points[0], points[0])
    dp[1] = (points[1], points[0] + points[1])

    for i in range(2, N):
        dp[i] = (max(dp[i-2])+points[i], dp[i-1][0]+points[i])
    print(max(dp[-1]))
