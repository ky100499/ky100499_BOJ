N = int(input())

squares = [i**2 for i in range(1, int(N**0.5)+1)]

dp = [N]*(N+1)
for i in range(1, N+1):
    if i in squares:
        dp[i] = 1
    else:
        for j in squares:
            if j > i//2:
                break
            else:
                dp[i] = min(dp[i], dp[i-j]+1)
print(dp[-1])
