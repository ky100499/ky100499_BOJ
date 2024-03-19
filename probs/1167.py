import sys
input = sys.stdin.readline

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

V = int(input())
edge = [[] for _ in range(V+1)]
ends = []
for _ in range(V):
    ipt = list(map(int, input().split()))
    i = 1
    while ipt[i] != -1:
        edge[ipt[0]].append((ipt[i], ipt[i+1]))
        i += 2
    if i // 2 == 1:
        end = ipt[0]
_, end = dfs(end, edge, 0, {})
ans, _ = dfs(end, edge, 0, {})
print(ans)
