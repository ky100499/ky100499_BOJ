import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import defaultdict as dd

while True:
    N, W = map(int, input().split())
    if N == W == 0:
        break
    V = dd(int)

    for _ in range(N):
        V[int(input()) // W] += 1

    k_max = max(V)
    v_max = max(V.values())

    ans = 0.01
    for k in range(k_max+1):
        ans += (1-k/k_max) * V[k]/v_max
    print(ans)
