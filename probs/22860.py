import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def dfs(path):
    ret = []
    for f in F[path]:
        if f in F:
            ret += dfs(f)
        else:
            ret += [f]
    return ret

N, M = map(int, input().split())

F = {'main': []}
for _ in range(N+M):
    p, f, c = input().split()

    if p in F:
        F[p].append(f)
    else:
        F[p] = [f]

    if c == '1' and f not in F:
        F[f] = []

for _ in range(int(input())):
    ans = dfs(input().rstrip().split('/')[-1])
    print(f'{len(set(ans))} {len(ans)}')
