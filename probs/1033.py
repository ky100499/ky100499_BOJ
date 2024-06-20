import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

def gcd(a, b):
    while b != 0:
        a, b = b, a%b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def ip(a, b):
    return (a[0]*b[0], a[1]*b[1])

N = int(input())
rat = [[(0,0)]*N for _ in range(N)]
for i in range(N):
    rat[i][i] = (1, 1)

for _ in range(N-1):
    a, b, p, q = map(int, input().split())
    rat[a][b] = (q, p)
    rat[b][a] = (p, q)

q = deque([])
for i in range(1, N):
    if rat[0][i] != (0, 0):
        q.append(i)
while q:
    i = q.popleft()

    for j in range(N):
        if i != j and rat[i][j] != (0, 0) and rat[0][j] == (0, 0):
            rat[0][j] = ip(rat[0][i], rat[i][j])
            q.append(j)

g = rat[0][0][0]
l = 1
for i in range(N):
    a, b = rat[0][i]
    _g = gcd(a, b)
    g = gcd(g, rat[0][i][0]//_g)
    l = lcm(l, rat[0][i][1]//_g)

print(*map(lambda x: l*x[0]//x[1]//g, rat[0]))
