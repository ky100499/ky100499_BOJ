import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())

cards = [0]*(2*N+1)
for _ in range(N):
    cards[int(input())] = 1

cnt, c = 0, 0
for i in range(2*N, 0, -1):
    if cards[i] == 0:
        c += 1
    elif c and cards[i] == 1:
        cnt, c = cnt+1, c-1
print(cnt)
