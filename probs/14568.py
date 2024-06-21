N = int(input())

cnt = 0
for i in range(2, N, 2):
    for j in range(1, N-i+1):
        k = N - i - j
        if j+2 <= k:
            cnt += 1
print(cnt)
