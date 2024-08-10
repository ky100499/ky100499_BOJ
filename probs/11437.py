import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
G = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

P = [-1]*(N+1)
D = [0]*(N+1)
P[1] = 0
q = deque([1])
while q:
    n = q.popleft()

    for c in G[n]:
        if P[c] == -1:
            P[c] = n
            D[c] = D[n]+1
            q.append(c)

for _ in range(int(input())):
    a, b = map(int, input().split())

    d = D[b] - D[a]
    if d < 0:
        a, b, d = b, a, -d

    for _ in range(d):
        b = P[b]

    while a != b:
        a, b = P[a], P[b]

    print(a)
