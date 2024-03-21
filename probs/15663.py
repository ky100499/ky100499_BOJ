def bt(arr, res):
    if len(res) == M:
        print(' '.join(map(str, res)))
    else:
        i = 0
        while i < len(arr):
            n = arr.pop(i)
            res.append(n)
            bt(arr[:], res)
            res.pop()
            arr = arr[:i] + [n] + arr[i:]
            while i+1 < len(arr) and arr[i] == arr[i+1]:
                i += 1
            i += 1

N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
bt(arr, [])
