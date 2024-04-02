N = int(input())
cnt = 0
for i in range(1, (N-1)//2+1):
    for j in range(max(i, N//2-i), (N-i)//2+1):
        k = N-i-j
        if i+j > k:
            cnt += 1
print(cnt)
