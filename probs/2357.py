import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)

def init(i, l, h):
    if l == h:
        ST[i] = [int(input())]*2
    else:
        m = (l+h)//2
        init(2*i, l, m)
        init(2*i+1, m+1, h)
        ST[i] = [min(ST[2*i][0], ST[2*i+1][0]), max(ST[2*i][1], ST[2*i+1][1])]

def find(i, l, h, s, e):
    if s <= l and h <= e:
        return ST[i]
    elif e < l or h < s:
        return [INF, 0]
    else:
        m = (l+h)//2
        f1, f2 = find(2*i, l, m, s, e), find(2*i+1, m+1, h, s, e)
        return [min(f1[0], f2[0]), max(f1[1], f2[1])]

N, M = map(int, input().split())
ST = [[INF, 0]]*(4*N)
init(1, 0, N-1)

for _ in range(M):
    a, b = map(int, input().split())
    print(*find(1, 0, N-1, a-1, b-1))
