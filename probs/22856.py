import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

input = open('input.txt', 'r').readline

def trav(node, rev):
    global ans

    c = child[node]
    if c == [None, None]:
        return
    elif c[0] == None:
        ans += 2 if rev else 1
        # print(f'{node} -> {c[1]} : {2 if rev else 1}')
        trav(c[1], rev)
    elif c[1] == None:
        ans += 2
        # print(f'{node} -> {c[0]} : 2')
        trav(c[0], True)
    else:
        ans += 4 if rev else 3
        # print(f'{node} -> {c[0], c[1]} : {4 if rev else 3}')
        trav(c[0], True)
        trav(c[1], rev)

N = int(input())

child = {}
for _ in range(N):
    a, b, c = map(int, input().split())
    if b == -1: b = None
    if c == -1: c = None
    child[a] = [b, c]
ans = 0
trav(1, False)
print(ans)
