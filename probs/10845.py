import sys
input = sys.stdin.readline

from collections import deque

q = deque()
for _ in range(int(input())):
    ipt = input().split()
    if ipt[0] == 'push':
        q.append(int(ipt[1]))
    elif ipt[0] == 'pop':
        print(q.popleft() if len(q) else -1)
    elif ipt[0] == 'size':
        print(len(q))
    elif ipt[0] == 'empty':
        print(0 if len(q) else 1)
    elif ipt[0] == 'front':
        if len(q):
            n = q.popleft()
            print(n)
            q.appendleft(n)
        else:
            print(-1)
    elif ipt[0] == 'back':
        if len(q):
            n = q.pop()
            print(n)
            q.append(n)
        else:
            print(-1)
