import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = int(1e9)+9
MAX = int(1e6)

# dp[i] -> i를 나타내는 방법의 수
# dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
#         1+(i-1)   2+(i-2)   3+(i-3)

dp = [0]*(MAX+1)
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(4, MAX+1):
    dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]) % MOD

for _ in range(int(input())):
    print(dp[int(input())])
