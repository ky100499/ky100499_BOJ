def c(n, r):
    x = 1
    for i in range(n-r+1, n+1):
        x *= i
    for i in range(1, r+1):
        x //= i
    return x

def h(n, r):
    return c(n+r-1, r)

N, K = map(int, input().split())
print(h(N+1, K-1) % 1_000_000_000)
