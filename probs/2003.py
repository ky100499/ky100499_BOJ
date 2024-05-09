import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
i, j = 0, 0
s1, s2 = 0, 0
cnt = 0
while j < N:
    s2 += A[j]
    while s1 + M < s2:
        s1 += A[i]
        i += 1
    if s1 + M == s2:
        cnt += 1
    j += 1
print(cnt)
