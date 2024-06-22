import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+7

# 이전 2칸까지 연결 + X 로 연결
# 이전 1칸까지 연결 + I 로 연결
# dp[i] = dp[i-1]+dp[i-2] -> Fibonacci
# dp[1] = 1, dp[2] = 2
dp = [1]*191230
for i in range(2, 191230):
    dp[i] = (dp[i-1]+dp[i-2]) % MOD

for _ in range(int(input())):
    print(dp[int(input())])
