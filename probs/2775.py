import sys
input = sys.stdin.readline

def fact(n):
    res = 1
    while n > 0:
        res *= n
        n -= 1
    return res

def c(n, r):
    return fact(n) // fact(n-r) // fact(r)

for _ in range(int(input())):
    k, n = (int(input()) for _ in range(2))
    print(c(k + n, k + 1))
