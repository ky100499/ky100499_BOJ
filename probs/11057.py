MOD = int(1e4)+7

N = int(input())

# dp[i] -> i로 끝나는 오르막 수
# 이전 단계에서 i 이하로 끝난 수의 개수 합
dp = list(range(1, 11))
for i in range(N-1):
    s = 0
    for j in range(10):
        s = (s + dp[j]) % MOD
        dp[j] = s
print(dp[-1])
