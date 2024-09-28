import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
R = list(map(int, input().split()))

if N == 1:
    print(0)
elif N == 2:
    print(max(R))
elif N == 3:
    print(max(R[0]+R[2], R[1]))
else:
    # [빔o, 빔x]
    # 대머리가 돼서 안 맞는거나 안 쏴서 안 맞는거나 그게 그거..
    dp = [[0]*2 for _ in range(N)]
    dp[0] = [R[0], 0]
    dp[1] = [R[1], R[0]]
    dp[2] = [R[0]+R[2], R[1]]

    for i in range(3, N):
        dp[i][0] = dp[i-1][1] + R[i]
        dp[i][1] = max(
            dp[i-1][0],
            dp[i-3][1]+R[i-2]+R[i-1]
        )

    print(max(dp[-1]))
