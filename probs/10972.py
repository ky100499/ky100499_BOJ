import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from bisect import bisect

N = int(input())
A = list(map(int, input().split()))

for i in range(N-1, 0, -1):
    if A[i] > A[i-1]:
        B = sorted(A[i:])
        j = bisect(B, A[i-1])
        A[i-1], B[j] = B[j], A[i-1]
        A = A[:i] + B
        print(*A, sep=' ')
        break
else:
    print(-1)
