import sys
input = sys.stdin.readline

def pow(m, p):
    if p == 0:
        return [[1, 0], [0, 1]]

    x = pow(m, p//2)
    if p % 2:
        return mul(mul(x, x), m)
    else:
        return mul(x, x)

def mul(a, b):
    ret = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                ret[i][j] += a[i][k]*b[k][j]
    return ret

H = int(input())
print(pow([[1,1],[2,0]], H)[0][0])
