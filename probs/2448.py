def tri(x, y, n):
    if n == 3:
        arr[y-3][x-1] = '*'
        arr[y-2][x-2], arr[y-2][x] = '*', '*'
        for i in range(x-3, x+2):
            arr[y-1][i] = '*'
    else:
        tri(x, y-n//2, n//2)
        tri(x-n//2, y, n//2)
        tri(x+n//2, y, n//2)

N = int(input())
arr = [[' ']*(2*N-1) for _ in range(N)]
tri(N, N, N)
print('\n'.join(map(lambda x: ''.join(x), arr)))
