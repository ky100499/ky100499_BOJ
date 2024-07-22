import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from collections import deque

for _ in range(int(input())):
    P = input().rstrip()
    N = int(input())
    if N:
        q = deque(map(int, input().rstrip()[1:-1].split(',')))
    else:
        input()
        q = deque()

    rev = 0
    for p in P:
        if p == 'R':
            rev ^= 1
        else:
            if not q:
                print('error')
                break

            if rev:
                q.pop()
            else:
                q.popleft()
    else:
        if rev:
            q = list(q)[::-1]
        print(f'[{",".join(map(str, q))}]')
