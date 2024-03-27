input = open('input.txt', 'r').readline

def mul(ma, mb):
    ret = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                ret[i][j] = (ma[i][k] * mb[k][j] + ret[i][j]) % 1000
    return ret

def power(m, p):
    if p == 1:
        return m

    tmp = power(m, p//2)
    if p % 2 == 0:
        return mul(tmp, tmp)
    else:
        return mul(m, mul(tmp, tmp))

N, B = map(int, input().split())
mat = [list(map(lambda x: int(x)%1000, input().split())) for _ in range(N)]
print('\n'.join(map(lambda x: ' '.join(map(str, x)), power(mat, B))))
