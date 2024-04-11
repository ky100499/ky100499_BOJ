import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def union(a, b):
    if a == b: return
    ra = find(a)
    rb = find(b)
    if A[ra] < A[rb]:
        parent[rb] = ra
    else:
        parent[ra] = rb

def find(a):
    if parent[a] == a: return a
    else:
        parent[a] = find(parent[a])
        return parent[a]

N, M, k = map(int, input().split())
A = [0]+list(map(int, input().split()))

parent = list(range(N+1))
for _ in range(M):
    union(*map(int, input().split()))

s = sum(map(lambda x: A[x], set(map(find, parent))))
print(s if s <= k else 'Oh no')
