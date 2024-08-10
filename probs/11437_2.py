import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque
from math import log2

MAX = 17

N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

P = [[-1]*MAX for _ in range(N+1)]
D = [0]*(N+1)
P[1][0] = 0
q = deque([1])
while q:
    n = q.popleft()

    for c in G[n]:
        if P[c][0] == -1:
            P[c][0] = n
            for i in range(1, MAX):
                P[c][i] = P[P[c][i-1]][i-1]
            D[c] = D[n]+1
            q.append(c)

for _ in range(int(input())):
    a, b = map(int, input().split())

    d = D[b] - D[a]
    if d < 0:
        a, b, d = b, a, -d

    while d:
        s = int(log2(d))
        b = P[b][s]
        d -= 2**s

    if a == b:
        print(a)
    else:
        for i in range(MAX-1, -1, -1):
            if P[a][i] != P[b][i]:
                a, b = P[a][i], P[b][i]
        print(P[a][0])
