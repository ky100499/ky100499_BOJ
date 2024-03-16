import sys
input = sys.stdin.readline

from collections import defaultdict as dd

for _ in range(int(input())):
    clothes = dd(int)
    for _ in range(int(input())):
        _, c = input().split()
        clothes[c] += 1

    ans = 1
    for k, v in clothes.items():
        ans *= (v+1)
    print(ans-1)
