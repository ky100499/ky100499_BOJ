import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dist(a, b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])

def bt(p, hp, n):
    global ans
    if dist(s, p) <= hp:
        ans = max(ans, n)

    if ans == l:
        return

    for i, milk in enumerate(milks):
        if not visited[i] and (d := dist(p, milk)) <= hp:
            visited[i] = 1
            bt(milk, hp - d + H, n+1)
            visited[i] = 0

N, M, H = map(int, input().split())
milks = []
for i in range(N):
    for j, v in enumerate(map(int, input().split())):
        if v == 1:
            s = (i, j)
        elif v == 2:
            milks.append((i, j))

visited = [0]*(l:=len(milks))

ans = 0
bt(s, M, 0)
print(ans)
