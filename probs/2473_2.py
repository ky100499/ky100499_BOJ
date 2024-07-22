import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = sorted(map(int, input().split()))

min_s = int(1e12)
for k in range(N):
    i, j = k+1, N-1
    while i < j:
        s = A[i]+A[j]+A[k]
        if abs(s) < min_s:
            min_s = abs(s)
            ans = [A[k], A[i], A[j]]

        if s > 0:
            j -= 1
        elif s < 0:
            i += 1
        else:
            break
    if min_s == 0:
        break
print(*ans)
