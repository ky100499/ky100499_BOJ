import sys
input = sys.stdin.readline

from collections import defaultdict as dd

N = int(input())
arr = map(int, input().split())
cnt = dd(int)
for n in arr:
    cnt[n] += 1

M = int(input())
ipt = map(lambda x: str(cnt[int(x)]), input().split())
print(' '.join(ipt))
