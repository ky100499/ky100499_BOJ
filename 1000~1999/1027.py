import sys
input = sys.stdin.readline

N = int(input())
b = list(map(int, input().split()))

cnt_max = 0
for i in range(N):
    cnt = 0
    grad_min, grad_max = 1e9, -1e9
    for j in reversed(range(i)):
        grad = (b[i] - b[j]) / (i - j)
        if grad < grad_min:
            grad_min = grad
            cnt += 1
    for j in range(i+1, N):
        grad = (b[i] - b[j]) / (i - j)
        if grad > grad_max:
            grad_max = grad
            cnt += 1
    cnt_max = max(cnt, cnt_max)
print(cnt_max)
