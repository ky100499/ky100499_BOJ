import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, S = map(int, input().split())
A = [0]
for a in map(int, input().split()):
    A.append(A[-1]+a)

if A[-1] < S:
    print(0)
else:
    ans = 10**5
    for i, a in enumerate(A):
        if a < S:
            continue
        for j in range(max(0, i-ans), i):
            if a - A[j] >= S:
                ans = min(ans, i-j)
            else:
                break
    print(ans)
