import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

ch = [
    [1, 1, 0,
     1, 0, 0,
     0, 0, 0],
    [1, 1, 1,
     0, 1, 0,
     0, 0, 0],
    [0, 1, 1,
     0, 0, 1,
     0, 0, 0],
    [1, 0, 0,
     1, 1, 0,
     1, 0, 0],
    [0, 1, 0,
     1, 1, 1,
     0, 1, 0],
    [0, 0, 1,
     0, 1, 1,
     0, 0, 1],
    [0, 0, 0,
     1, 0, 0,
     1, 1, 0],
    [0, 0, 0,
     0, 1, 0,
     1, 1, 1],
    [0, 0, 0,
     0, 0, 1,
     0, 1, 1],
]

def click(b, n):
    ret = [0]*9
    for i, v in enumerate(b):
        ret[i] = v ^ ch[n][i]
    return ret

for _ in range(int(input())):
    b = []
    for _ in range(3):
        b += list(map(lambda x: int(x=='*'), input().strip()))

    q = deque([(b, 0, [])])
    while q:
        b, c, v = q.popleft()
        if sum(b) == 0:
            print(c)
            break
        for i in range(9):
            if i not in v:
                q.append((click(b, i), c+1, v+[i]))
