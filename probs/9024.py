import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N, K = map(int, input().split())
    A = sorted(map(int, input().split()))

    d_min, cnt = int(1e9), 0
    i, j = 0, N-1

    while i < j:
        s = A[i]+A[j]
        d = abs(K-s)

        if d < d_min:
            d_min = d
            cnt = 1
        elif d == d_min:
            cnt += 1

        if s <= K:
            i += 1
        if s >= K:
            j -= 1

    print(cnt)
