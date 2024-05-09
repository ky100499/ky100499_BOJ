import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
group = {}
member = {}

for _ in range(N):
    g = input().strip()
    group[g] = []
    for _ in range(int(input())):
        m = input().strip()
        group[g].append(m)
        member[m] = g
    group[g].sort()

for _ in range(M):
    q = input().strip()
    t = int(input())

    if t:
        print(member[q])
    else:
        print(*group[q], sep='\n')
