input = open('input.txt', 'r').readline

def dfs(cur, par, paired):
    print(cur, par, paired)
    for c in children[cur]:
        print(cur, c)
        dfs(c, cur, paired)
        if cur in paired:
            return paired

    if par:
        paired += [cur, par]
    return paired

for _ in range(int(input())):
    children = {1: []}
    N, *parent = map(int, input().split())
    if len(parent) != N-1:
        print("???")

    for i, p in enumerate(parent):
        children[p].append(i+2)
        children[i+2] = []

    print(dfs(1, None, []))
