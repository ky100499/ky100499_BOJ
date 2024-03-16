import sys
input = sys.stdin.readline

from collections import deque

for _ in range(int(input())):
    A, B = map(int, input().split())

    q = deque([(A, '')])
    visited = {}
    while q:
        n, hist = q.popleft()
        if n == B:
            print(hist)
            break
        if n in visited:
            continue
        visited[n] = 1

        q.append((2 * n % 10000,                hist + 'D'))
        q.append((n-1 if n>0 else 9999,         hist + 'S'))
        q.append((n % 1000 * 10 + n // 1000,    hist + 'L'))
        q.append((n // 10 + n % 10 * 1000,      hist + 'R'))
