MOD = 9901

N = int(input())
dp = [1, 1, 1]  #[XX, OX, XO]
for _ in range(1, N):
    dp = list(map(lambda x: x%MOD, [sum(dp), dp[0]+dp[2], dp[0]+dp[1]]))
print(sum(dp)%MOD)
