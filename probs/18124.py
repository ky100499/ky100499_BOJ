N = int(input())

if N == 1:
    print(0)
    exit(0)

cnt, cut = 1, 0
while True:
    if cnt * 2 < N:
        cut += cnt
        cnt *= 2
    else:
        print(cut + (N+1)//2)
        break
