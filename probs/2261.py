import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)

def sq(n):
    return n*n

def dist(a, b):
    return sq(a[0]-b[0]) + sq(a[1]-b[1])

def solve(l, h):
    if h <= l:
        return INF

    m = (l+h)//2
    d = min(solve(l, m), solve(m+1, h))

    tmp = [A[m]]
    for i in reversed(range(l, m)):
        if sq(A[i][0]-A[m][0]) >= d:
            break
        tmp.append(A[i])
    for i in range(m+1, h):
        if sq(A[i][0]-A[m][0]) >= d:
            break
        tmp.append(A[i])
    tmp.sort(key=lambda x: x[::-1])

    for i in range(len(tmp)):
        for j in range(i+1, len(tmp)):
            if sq(tmp[i][1]-tmp[j][1]) >= d:
                break
            d = min(d, dist(tmp[i], tmp[j]))

    return d

N = int(input())
A = [tuple(map(int, input().split())) for _ in range(N)]
A.sort()

print(solve(0, N))
