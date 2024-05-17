def bt(pick, arr):
    if len(pick) == M:
        print(*pick)
    elif arr:
        for i, n in enumerate(arr):
            bt(pick+[n], arr[i+1:])

N, M = map(int, input().split())
bt([], sorted(map(int, input().split())))
