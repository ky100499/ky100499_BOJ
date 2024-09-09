import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def update(i, l, h, k, v):
    if l == h:
        ST[i] = v
    else:
        m = (l+h)//2
        if l <= k <= m:
            update(2*i, l, m, k, v)
        elif m < k <= h:
            update(2*i+1, m+1, h, k, v)
        ST[i] = ST[2*i] + ST[2*i+1]

def find(i, l, h, s, e):
    if s <= l and h <= e:
        return ST[i]
    elif e < l or h < s:
        return 0
    else:
        m = (l+h)//2
        return find(2*i, l, m, s, e) + find(2*i+1, m+1, h, s, e)

N, M, K = map(int, input().split())
ST = [0]*(4*N)
for i in range(N):
    update(1, 0, N-1, i, int(input()))

for _ in range(M+K):
    a, b, c = map(int, input().split())
    if a == 1:
        update(1, 0, N-1, b-1, c)
    else:
        print(find(1, 0, N-1, b-1, c-1))
