from collections import deque

q = deque(range(1, int(input())+1))
while q:
    print(q.popleft(), end=' ')
    q.rotate(-1)
