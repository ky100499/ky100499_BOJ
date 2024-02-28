T = int(input())

for i in range(T):
    N = int(input())

    count = [0 for i in range(N)]
    count.extend([1, 0])

    while N > 1:
        count[N - 1] += count[N]
        count[N - 2] += count[N]
        N -= 1

    print(' '.join(map(str, count[:2])))
