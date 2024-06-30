def count(n):
    cnt = 0
    while n:
        cnt += n&1
        n >>= 1
    return cnt

N, K = map(int, input().split())

ans, i = 0, 1
while count(N) > K:
    while N&i == 0:
        i <<= 1
    N += i
    ans += i
print(ans)
