import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
D = [int(input()) for _ in range(N)]

MAX = sum(D)
x, y = 0, 0
ans = 0
for i in range(N):
    y = x
    for j in range(i, i+N):
        y += D[j%N]
        ans = max(ans, min(y-x, MAX-y+x))
        if y-x > MAX//2:
            break
    x += D[i]
print(ans)
