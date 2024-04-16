import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = [int(input()) for _ in range(N)]
A.sort()

a, b = 0, 0
ans = 10**10

while b < N:
    d = A[b]-A[a]
    if d > M:
        ans = min(ans, d)
        a += 1
    elif d < M:
        b += 1
    else:
        ans = M
        break
print(ans)
