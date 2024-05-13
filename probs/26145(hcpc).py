import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
S = list(map(int, input().split())) + [0]*M

for i in range(N):
    for j, v in enumerate(map(int, input().split())):
        S[i] -= v
        S[j] += v
print(*S)
