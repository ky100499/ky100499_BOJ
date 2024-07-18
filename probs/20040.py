import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def union(a, b):
    pa, pb = find(a), find(b)

    if pa < pb:
        U[pb] = pa
        find(b)
    elif pa > pb:
        U[pa] = pb
        find(a)

def find(x):
    if U[x] != x:
        U[x] = find(U[x])

    return U[x]

N, M = map(int, input().split())

U = [i for i in range(N)]

for i in range(1, M+1):
    a, b = map(int, input().split())

    if find(a) == find(b):
        print(i)
        break

    union(a, b)
else:
    print(0)
