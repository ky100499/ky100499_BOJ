import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

mv = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
]

N = int(input())
apples = [tuple(map(int, input().split())) for _ in range(int(input()))]
moves = deque()
for _ in range(int(input())):
    x, c = input().split()
    moves.append((int(x), c))

t, d = 0, 0
snake = deque([(1, 1)])
while True:
    t += 1
    x, y = snake[-1]
    x, y = x+mv[d][0], y+mv[d][1]

    if not (0 < x <= N and 0 < y <= N):
        break
    elif (x, y) in snake:
        break
    elif (x, y) in apples:
        i = apples.index((x, y))
        apples = apples[:i] + apples[i+1:]
    else:
        snake.popleft()

    snake.append((x, y))

    if moves and moves[0][0] == t:
        _, c = moves.popleft()
        if c == 'L':
            d = (d-1) % 4
        elif c == 'D':
            d = (d+1) % 4
print(t)
