def bt(pick, arr):
    if len(pick) == M:
        print(*pick)
    else:
        for i, n in enumerate(arr):
            bt(pick+[n], arr[:i]+arr[i+1:])

N, M = map(int, input().split())
bt([], list(range(1, N+1)))
