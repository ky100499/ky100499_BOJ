def fact(n):
    res = 1
    while n > 0:
        res *= n
        n -= 1
    return res

def c(n, r):
    return fact(n) // fact(n-r) // fact(r)

print(c(*map(int, input().split())))
