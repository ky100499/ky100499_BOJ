import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

N, K, M = map(int, input().split())

tubes = [list(map(int, input().split())) for _ in range(M)]

q = deque([(1, 1)])
visited = {}
while q:
    n, d = q.popleft()

    if n == N:
        print(d)
        break

    if n in visited:
        continue
    visited[n] = 1

    for tube in tubes:
        if n in tube:
            for t in tube:
                if t != n and t not in visited:
                    q.append((t, d+1))
