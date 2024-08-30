import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

M = int(input())
L = []
while True:
    a, b = map(int, input().split())
    if a == b == 0:
        break
    L.append((a, b))
L.sort()

x = 0
r = -50000
cnt = 0
for a, b in L:
    if a <= x:
        r = max(r, b)
    else:
        if a <= r:
            cnt += 1
            x = r
            r = b
        else:
            print(0)
            break
    if x >= M:
        print(cnt)
        break
    elif r >= M:
        print(cnt+1)
        break
else:
    print(0)
