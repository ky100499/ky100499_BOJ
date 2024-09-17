import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from bisect import bisect_left as lb

N = int(input())
A = list(map(int, input().split()))

LIS, idx, l = [], [0]*N, 0
for i in range(N):
    x = lb(LIS, A[i])

    idx[i] = x
    if x == l:
        LIS.append(A[i])
        l += 1
    else:
        LIS[x] = A[i]

print(l)

ans = [0]*l
for i in reversed(range(N)):
    if idx[i] == l-1:
        l -= 1
        ans[l] = A[i]
print(*ans)
