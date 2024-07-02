N, M = map(int, input().split())

def count(n, m):
    cnt, mod = 0, m
    while mod <= n:
        cnt += n // mod
        mod *= m
    return cnt

print(
    min(
        count(N, 5) - count(M, 5) - count(N-M, 5),
        count(N, 2) - count(M, 2) - count(N-M, 2)
    )
)
