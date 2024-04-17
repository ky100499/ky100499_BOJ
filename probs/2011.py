import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

s = list(map(int, input().strip()))
N = len(s)
dp = [[0, 0] for _ in range(N)]
if N == 1:
    print(int(0 < s[0] < 10))
elif s[0] == 0:
    print(0)
elif s[1] == 0 and 10*s[0]+s[1] > 26:
    print(0)
else:
    dp[0][0] = 1
    dp[1][0] = int(s[1] != 0)
    dp[1][1] = int(10*s[0]+s[1] <= 26)
    for i in range(2, N):
        if 1 <= s[i] <= 9:
            dp[i][0] = sum(dp[i-1])

        if s[i-1] != 0 and 1 <= s[i-1]*10+s[i] <= 26:
            dp[i][1] = sum(dp[i-2])

        if sum(dp[i]) == 0:
            break
    print(sum(dp[-1]) % 1000000)
