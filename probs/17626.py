n = int(input())

dp = [0, 1] + [5] * (n-1)
for i in range(2, n+1):
    if i == int(i ** 0.5) ** 2:
        dp[i] = 1
    else:
        for j in range(1, int(i**0.5)+1):
            dp[i] = min(dp[i], 1+dp[i-j**2])
            if dp[i] == 2:
                break
print(dp[n])
