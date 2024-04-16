from collections import deque

A, B, C = map(int, input().split())

q = deque([(0, 0, C)])
visited = set()
ans = set()
while q:
    a, b, c = q.popleft()
    if (a, b, c) in visited:
        continue
    visited.add((a, b, c))

    if a == 0:
        ans.add(c)

    if a < A:
        if a+b < A:
            q.append((a+b, 0, c))
        else:
            q.append((A, a+b-A, c))
        if a+c < A:
            q.append((a+c, b, 0))
        else:
            q.append((A, b, a+c-A))
    if b < B:
        if a+b < B:
            q.append((0, a+b, c))
        else:
            q.append((a+b-B, B, c))
        if b+c < B:
            q.append((a, b+c, 0))
        else:
            q.append((a, B, b+c-B))
    if c < C:
        if a+c < C:
            q.append((0, b, a+c))
        else:
            q.append((a+c-C, b, C))
        if b+c < C:
            q.append((a, 0, b+c))
        else:
            q.append((a, b+c-C, C))
print(*sorted(list(ans)))
