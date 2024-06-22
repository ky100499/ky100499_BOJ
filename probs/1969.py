import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

N, M = map(int, input().split())
S = [input().rstrip() for _ in range(N)]

B = sorted('ATGC')
H = 0

for i in range(M):
    cnt = dd(int)
    for j in range(N):
        cnt[S[j][i]] += 1

    n, m = '', 0
    for b in B:
        if cnt[b] > m:
            m = cnt[b]
            n = b
    H += N - m
    print(n, end='')
print()
print(H)
