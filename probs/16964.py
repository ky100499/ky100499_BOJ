import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N = int(input())
G = [set() for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    G[a].add(b)
    G[b].add(a)

A = list(map(int, input().split()))
if A[0] == 1:
    S = deque([1])
    for a in A[1:]:
        while S:
            if G[S[-1]]:
                break
            else:
                S.pop()
        if not S:
            print(0)
            break

        if a in G[S[-1]]:
            G[S[-1]].discard(a)
            G[a].discard(S[-1])
            S.append(a)
        else:
            print(0)
            break
    else:
        print(1)
else:
    print(0)
