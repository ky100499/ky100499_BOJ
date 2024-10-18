import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

N, S = map(int, input().split())
A = list(map(int, input().split()))

LS, RS = dd(int), dd(int)
for i in range(N//2):
    for k, v in list(LS.items()):
        LS[k+A[i]] += v
    LS[A[i]] += 1
for i in range(N//2, N):
    for k, v in list(RS.items()):
        RS[k+A[i]] += v
    RS[A[i]] += 1

cnt = LS[S] + RS[S]
for k, v in LS.items():
    cnt += v * RS[S-k]
print(cnt)
