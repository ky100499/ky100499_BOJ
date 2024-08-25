import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())

ans = [i for i in range(N+1)]
for _ in range(M):
    x, y = map(int, input().split())
    ans[x] += 1
    ans[y] -= 1

for i, v in enumerate(sorted(ans)):
    if i != v:
        print(-1)
        break
else:
    print(*ans[1:])
