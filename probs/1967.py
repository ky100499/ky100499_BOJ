import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def dfs(node, edge, depth, visited):
    visited[node] = 1

    res = []
    if len(edge[node]) == 1 and edge[node][0][0] in visited:
        return (depth, node)
    else:
        for n, d in edge[node]:
            if n not in visited:
                res.append(dfs(n, edge, depth+d, visited))
        return max(res)

n = int(input())
if n == 1:
    print(0)
else:
    edge = [[] for _ in range(n+1)]
    end = 1
    for _ in range(n-1):
        p, c, d = map(int, input().split())
        edge[p].append((c, d))
        edge[c].append((p, d))
        end = c
    _, end = dfs(end, edge, 0, {})
    ans, _ = dfs(end, edge, 0, {})
    print(ans)
