import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from bisect import bisect

def get(l, idx):
    return list(map(lambda x: l[x], idx))

N = int(input())
A = sorted(map(int, input().split()))

min_s = int(1e12)
for i in range(N-1):
    for j in range(i+1, N):
        s = A[i]+A[j]
        k = bisect(A, -s)

        if k < N and i != k and j != k:
            ss = abs(sum(get(A, [i, j, k])))
            if ss < min_s:
                ans = sorted(get(A, [i, j, k]))
                min_s = ss

        if k > 0 and i != k-1 and j != k-1:
            ss = abs(sum(get(A, [i, j, k-1])))
            if ss < min_s:
                ans = sorted(get(A, [i, j, k-1]))
                min_s = ss

        if min_s == 0:
            break
    if min_s == 0:
        break
print(*ans)
