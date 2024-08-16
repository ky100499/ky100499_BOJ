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

T = [[] for _ in range(N+1)]
V = [0]*(N+1)
q = deque([1])
while q:
    n = q.popleft()

    if V[n]:
        continue
    V[n] = 1

    for c in G[n]:
        if not V[c]:
            T[n].append(c)
            q.append(c)

A = list(map(int, input().split()))
if A[0] == 1:
    S = deque([1])
    V = [0]*(N+1)
    V[1] = 1
    for a in A[1:]:
        while S:
            if T[S[-1]]:
                break
            else:
                S.pop()
        if not S:
            print(0)
            break

        if a in T[S[-1]]:
            T[S[-1]].remove(a)
            V[a] = 1
            S.append(a)
        else:
            print(0)
            break
    else:
        print(1)
else:
    print(0)
