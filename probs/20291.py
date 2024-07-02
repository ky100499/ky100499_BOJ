import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

N = int(input())
d = dd(int)

for _ in range(N):
    _, e = input().rstrip().split('.')
    d[e] += 1

for e, n in sorted(d.items()):
    print(e, n)
