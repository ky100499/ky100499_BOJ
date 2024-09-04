import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from heapq import heappush, heappop

N, M = map(int, input().split())
A, B, V = [], [], [0]*(N+M+1)
for i, v in enumerate(map(int, input().split())):
    heappush(A, (v, i+1))
    V[i+1] = v
for i, v in enumerate(map(int, input().split())):
    heappush(B, (v, i+N+1))
    V[i+N+1] = v

for _ in range(int(input())):
    q = input()
    if q[0] == 'U':
        i, v = map(int, q[1:].split())
        heappush(A if i <= N else B, (v, i))
        V[i] = v
    else:
        while A[0][0] != V[A[0][1]]:
            heappop(A)
        while B[0][0] != V[B[0][1]]:
            heappop(B)
        print(A[0][1], B[0][1])
