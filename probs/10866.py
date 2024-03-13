import sys
input = sys.stdin.readline

from collections import deque

q = deque()
for _ in range(int(input())):
    ipt = input().split()
    if ipt[0] == 'push_front':
        q.appendleft(int(ipt[1]))
    elif ipt[0] == 'push_back':
        q.append(int(ipt[1]))
    elif ipt[0] == 'pop_front':
        print(q.popleft() if len(q) else -1)
    elif ipt[0] == 'pop_back':
        print(q.pop() if len(q) else -1)
    elif ipt[0] == 'size':
        print(len(q))
    elif ipt[0] == 'empty':
        print(0 if len(q) else 1)
    elif ipt[0] == 'front':
        if len(q):
            print(q[0])
        else:
            print(-1)
    elif ipt[0] == 'back':
        if len(q):
            print(q[-1])
        else:
            print(-1)
