import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

MOD = 998_244_353

W, H, K, T = map(int, input().split())
ans = 1

for _ in range(K):
    x, y = map(int, input().split())
    w = min(W, x+T) - max(1, x-T) + 1
    h = min(H, y+T) - max(1, y-T) + 1
    ans = (ans * w * h) % MOD

print(ans)
