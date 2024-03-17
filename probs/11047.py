N, K = map(int, input().split())
coins = []
for _ in range(N):
    coins.append(int(input()))
ans = 0
for coin in coins[::-1]:
    ans += K // coin
    K %= coin
print(ans)
