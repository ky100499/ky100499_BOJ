MOD = int(1e9)+7

def power(m, p):
    if p == 1:
        return m

    x = power(m, p//2)
    if p % 2:
        return mul(mul(x, x), m)
    else:
        return mul(x, x)

def mul(a, b):
    c = [[0]*2,[0]*2]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD
    return c

N = int(input())
f = [[1, 1], [1, 0]]
print(power(f, N)[0][1])
