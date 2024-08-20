import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)
MAX = int(1e6)

N = int(input())
X = list(map(int, input().split()))
S = [INF]*(MAX+1)

for x in X:
    S[x] = 0

h = max(X)
for x in X:
    for y in range(2*x, h+1, x):
        if S[y] != INF:
            S[x], S[y] = S[x]+1, S[y]-1

print(*map(lambda x: S[x], X))
