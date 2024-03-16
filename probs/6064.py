def gcd(a, b):
    if a < b: a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

for _ in range(int(input())):
    M, N, x, y = map(int, input().split())
    k = 0
    g = lcm(M, N)
    while True:
        year = k * M + x
        if year > g:
            print(-1)
            break
        elif year % N == y % N:
            print(year)
            break
        k += 1
