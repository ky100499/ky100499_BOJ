import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, A, B, *D = map(int, input().split())
A, B = A-1, B-1

q = deque([(A, B, 0, 0)])
visited = [[[-1]*2 for _ in range(N)] for _ in range(N)]
while q:
    a, b, t, n = q.popleft()

    if a == b:
        print(n)
        break

    if visited[a][b][t] >= 0:
        continue
    visited[a][b][t] = n

    q.append(((a+D[0]*(t==0))%N, (b+D[1]*(t==1))%N, t^1, n+1))
    q.append(((a-D[0]*(t==0))%N, (b-D[1]*(t==1))%N, t^1, n+1))
else:
    print('Evil Galazy')
