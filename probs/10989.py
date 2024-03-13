import sys
input = sys.stdin.readline

from collections import defaultdict as dd

cnt = dd(int)
for _ in range(int(input())):
    cnt[int(input())] += 1
for x in sorted(cnt.keys()):
    for _ in range(cnt[x]):
        print(x)
