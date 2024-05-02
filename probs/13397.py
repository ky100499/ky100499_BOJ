import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def div(d):
    cnt = 1
    l, h = 10000, 0
    for a in A:
        l = min(l, a)
        h = max(h, a)
        if h-l > d:
            cnt += 1
            l, h = a, a
    return cnt

N, M = map(int, input().split())
A = list(map(int, input().split()))

l, h = 0, 10000
while l <= h:
    m = (l+h)//2
    if div(m) > M:
        l = m+1
    else:
        ans = m
        h = m-1
print(ans)
