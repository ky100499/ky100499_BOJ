import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def bt(c, i):
    global ans

    if c == (1<<26)-1:
        ans += 1 << (N-i)
        return

    if i == N:
        return

    bt(c, i+1)
    bt(c|W[i], i+1)

N = int(input())
W = []
for _ in range(N):
    x = 0
    for c in input().rstrip():
        x |= 1 << (ord(c) - ord('a'))
    W.append(x)

ans = 0
bt(0, 0)
print(ans)
