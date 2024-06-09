import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from bisect import bisect

N = int(input())
S = list(map(int, input().split()))

a = (b := bisect(S, 0)) - 1
if a == -1:
    print(*S[:2])
elif b == N:
    print(*S[-2:])
else:
    min_v = int(1e10)

    if a > 0 and abs(min_v) > abs(S[a]+S[a-1]):
        min_v = S[a]+S[a-1]
        ans = (S[a-1], S[a])
    if b < N-1 and abs(min_v) > abs(S[b]+S[b+1]):
        min_v = S[b]+S[b+1]
        ans = (S[b], S[b+1])
    if abs(min_v) > abs(S[a]+S[b]):
        min_v = S[a]+S[b]
        ans = (S[a], S[b])

    while a >= 0 and b < N:
        new_v = S[a]+S[b]
        if abs(min_v) > abs(new_v):
            min_v = new_v
            ans = (S[a], S[b])

        if min_v == 0:
            break

        if new_v > 0:
            a -= 1
        elif new_v < 0:
            b += 1
    print(*ans)
