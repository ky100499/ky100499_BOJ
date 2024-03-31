import sys
input = sys.stdin.readline

blocks = [int(input()) for _ in range((int(input())))]
m, c = 0, 0
for n in reversed(blocks):
    if n > m:
        c += 1
        m = n
print(c)
