import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def union(a, b):
    pa = find(a)
    pb = find(b)

    if pa != pb:
        parent[pb] = pa

def find(a):
    if parent[a] == a:
        return a
    else:
        return find(parent[a])

N = int(input())
M = int(input())

parent = [i for i in range(N+1)]

for i in range(N):
    for j, c in enumerate(map(int, input().split())):
        if c:
            union(i+1, j+1)

trip = list(map(int, input().split()))
for i in range(M-1):
    if find(trip[i]) != find(trip[i+1]):
        print('NO')
        break
else:
    print('YES')
