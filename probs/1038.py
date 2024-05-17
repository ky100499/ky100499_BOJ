def bt(n, arr, dgt):
    global N
    if dgt == 0:
        if N == 0:
            print(n)
            N = -1
            return
        N -= 1
    else:
        for i, a in enumerate(arr):
            if N >= 0:
                bt(10*n+a, arr[:i], dgt-1)


N = int(input())
for i in range(1, 11):
    if N >= 0:
        bt(0, list(range(10)), i)
if N >= 0:
    print(-1)
