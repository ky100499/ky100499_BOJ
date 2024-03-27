import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque, defaultdict as dd

N = int(input())
edges = dd(list)
for _ in range(N-1):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

parent = dd(int)
q = deque([1])
while q:
    node = q.popleft()
    for c in edges[node]:
        if c not in parent:
            parent[c] = node
            q.append(c)
for n, p in sorted(parent.items()):
    if n != 1:
        print(p)
