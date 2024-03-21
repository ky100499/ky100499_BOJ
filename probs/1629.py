def mul(a, b, c):
    if b == 0: return 1
    if b == 1: return a % c

    d = mul(a, b//2, c) % c
    return (d * d * (a if b % 2 else 1)) % c

A, B, C = map(int, input().split())
print(mul(A%C, B, C))
