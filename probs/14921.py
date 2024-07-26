import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
A = sorted(map(int, input().split()))

i, j = 0, N-1
ans = int(1e9)
while i < j:
    s = A[i]+A[j]
    if abs(ans) > abs(s):
        ans = s

    if s > 0:
        j -= 1
    elif s < 0:
        i += 1
    else:
        break
print(ans)
