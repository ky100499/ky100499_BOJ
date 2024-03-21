def bt(arr, res):
    if len(res) == M:
        print(' '.join(map(str, res)))
    else:
        for i, n in enumerate(arr):
            res.append(n)
            bt(arr[i:], res)
            res.pop()

N, M = map(int, input().split())
arr = list(set(map(int, input().split())))
arr.sort()
bt(arr, [])
