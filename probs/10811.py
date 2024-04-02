import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
l = list(range(1, N+1))
for _ in range(M):
    i, j = map(int, input().split())
    while i < j:
        l[i-1], l[j-1] = l[j-1], l[i-1]
        i += 1
        j -= 1
print(*l)
