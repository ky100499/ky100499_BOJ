import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, K = map(int, input().split())
ipt = []
for _ in range(N):
    n, g, s, b = map(int, input().split())
    if n == K:
        ipt = [(n, g, s, b)] + ipt
    else:
        ipt.append((n, g, s, b))
ipt.sort(key=lambda x: (x[1], x[2], x[3]), reverse=True)

for i, (n, _, _, _) in enumerate(ipt):
    if n == K:
        print(i+1)
        break
