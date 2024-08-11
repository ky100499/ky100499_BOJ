import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque
from itertools import combinations as c

N = int(input())
P = [0]+list(map(int, input().split()))
T = sum(P)
G = [[] for _ in range(N+1)]
for i in range(1, N+1):
    _, *G[i] = map(int, input().split())

ans = int(1e9)
for i in range(1, N):
    for Z in c(range(1, N+1), i):
        V = [0]*(N+1)
        q = deque([Z[0]])
        while q:
            s = q.popleft()

            if V[s]:
                continue
            V[s] = 1

            for t in G[s]:
                if t in Z and not V[t]:
                    q.append(t)

        Z2 = tuple(set(range(1, N+1))-set(Z))
        q = deque([Z2[0]])
        while q:
            s = q.popleft()

            if V[s]:
                continue
            V[s] = 2

            for t in G[s]:
                if t not in Z and not V[t]:
                    q.append(t)

        if V.count(0) == 1:
            s = 0
            for i, v in enumerate(V):
                s += P[i] if v == 1 else -P[i]
            ans = min(ans, abs(s))
print(-1 if ans==int(1e9) else ans)
