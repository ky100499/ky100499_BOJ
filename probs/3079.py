import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
T = [int(input()) for _ in range(N)]

l, h = 1, 10**18
while l <= h:
    m = (l+h)//2
    if sum(map(lambda x: m//x, T)) < M:
        l = m+1
    else:
        ans = m
        h = m-1
print(ans)
