import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, C = map(int, input().split())
X = [int(input()) for _ in range(N)]
X.sort()

l, h = 0, 10**9
while l <= h:
    m = (l+h) // 2

    cnt, c = 1, X[0]
    for x in X:
        if x-c >= m:
            cnt += 1
            c = x

    if cnt < C:
        h = m-1
    else:
        ans = m
        l = m+1
print(ans)
