def rev(n):
    r = 0
    while n:
        r = r * 10 + n % 10
        n //= 10
    return r

x, y = map(int, input().split())
print(rev(rev(x)+rev(y)))
