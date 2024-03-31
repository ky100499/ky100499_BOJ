def zero(n):
    cnt = 0
    while n:
        if n % 10 == 0:
            cnt += 1
        n //= 10
    return cnt

for _ in range(int(input())):
    N, M = map(int, input().split())
    cnt = 0
    while N <= M:
        cnt += zero(N) if N > 0 else 1
        N += 1
    print(cnt)
