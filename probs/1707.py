import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

for _ in range(int(input())):
    V, E = map(int, input().split())

    edges = [set() for _ in range(V+1)]
    for _ in range(E):
        u, v = map(int, input().split())
        edges[u].add(v)
        edges[v].add(u)

    group = [-1]*(V+1)
    for i in range(1, V+1):
        if group[i] != -1:
            continue
        group[i] = 0

        q = deque([i])
        while q:
            u = q.popleft()
            for v in edges[u]:
                if group[v] == -1:
                    group[v] = group[u] ^ 1
                    q.append(v)
                elif group[v] == group[u]:
                    print('NO')
                    break
            else:
                continue
            break
        else:
            continue
        break
    else:
        print('YES')
