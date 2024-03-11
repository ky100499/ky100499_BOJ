import sys
input = sys.stdin.readline

K, N = map(int, input().split())

cables = []
for _ in range(K):
    cables.append(int(input()))

b, t = 1, sum(cables) // N
while True:
    if t == b:
        print(b)
        break
    elif t - b == 1:
        if sum(map(lambda x: x // t, cables)) >= N:
            print(t)
        else:
            print(b)
        break
    mid = (b + t) // 2
    if sum(map(lambda x: x // mid, cables)) < N:
        t = mid
    else:
        b = mid
