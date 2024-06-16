import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e10)

N = int(input())
pts = sorted([tuple(map(int, input().split())) for _ in range(N)])

S, E = -INF, INF
l = 0
for x, y in pts:
    if S == -INF:
        S, E = x, y
        continue

    if E < x:
        l += E-S
        S, E = x, y
    else:
        E = max(E, y)
print(l+E-S)
