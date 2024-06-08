import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from bisect import bisect_right

N = int(input())

A = {a:i for i, a in enumerate(map(int, input().split()))}
B = list(map(lambda x: A[int(x)], input().split()))

dp = [B[0]]
for b in B[1:]:
    if b > dp[-1]:
        dp.append(b)
    else:
        i = bisect_right(dp, b)
        dp[i] = b

print(len(dp))
