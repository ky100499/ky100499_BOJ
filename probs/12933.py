import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

sound = {c:i for i, c in enumerate('quack')}

ducks = []
for c in input().strip():
    for duck in ducks:
        if c == 'q' and not duck:
            duck.append(c)
            break
        elif duck and sound[c] == sound[duck[-1]]+1:
            if c == 'k':
                while duck:
                    duck.pop()
            else:
                duck.append(c)
            break
    else:
        ducks.append(deque([c]))

for duck in ducks:
    if duck:
        print(-1)
        break
else:
    print(len(ducks))
