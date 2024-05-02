import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

N, K = map(int, input().split())
A = list(map(int, input().split()))

s = 0
d = dd(int)
cnt = 0
for a in A:
    s += a
    cnt += d[s-K] + int(s==K)
    d[s] += 1
print(cnt)
