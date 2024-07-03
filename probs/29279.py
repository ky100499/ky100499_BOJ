import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

S, N, M = map(int, input().split())
U = 0

for _ in range(N+M):
    if int(input()):
        U += 1
    else:
        U -= 1

    if S < U:
        S *= 2

print(S)
