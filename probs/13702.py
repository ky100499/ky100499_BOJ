import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]

l, h = 0, 2147483647
ans = 0
while l <= h:
    m = (l+h) // 2

    c = 0
    for a in A:
        c += a // m

    if c < K:
        h = m-1
    else:
        ans = m
        l = m+1
print(ans)
