import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
scores = list(map(int, input().split()))

ans = [0]*(N+1)

for i in range(1, N+1):
    l, h = 10000, 0
    for j in range(i, 0, -1):
        h = max(h, scores[j-1])
        l = min(l, scores[j-1])
        ans[i] = max(ans[i], ans[j-1]+h-l)

print(ans[N])
