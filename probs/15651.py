def bt(pick, arr):
    if len(pick) == M:
        print(*pick)
    else:
        for n in arr:
            bt(pick+[n], arr)

N, M = map(int, input().split())
bt([], list(range(1, N+1)))
