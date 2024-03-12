import sys
input = sys.stdin.readline

from collections import deque

while True:
    s = input().rstrip()
    if s == '.':
        break

    q = deque()
    for c in s:
        if c == '.':
            if len(q):
                print('no')
            else:
                print('yes')
            break
        elif c in '([':
            q.append(c)
        elif c == ')' and (len(q) == 0 or q.pop() != '('):
            print('no')
            break
        elif c == ']' and (len(q) == 0 or q.pop() != '['):
            print('no')
            break
