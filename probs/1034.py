import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

N, M = map(int, input().split())
L = dd(int)
for _ in range(N):
    L[input().rstrip()] += 1
K = int(input())

ans = 0
for k, v in L.items():
    c = k.count('0')
    if K >= c and (K-c) % 2 == 0:
        ans = max(ans, v)
print(ans)
