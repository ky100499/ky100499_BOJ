N, r, c = map(int, input().split())

lt = 0
mat = [[0, 1], [2, 3]]
while N:
    lt += mat[r // 2 ** (N-1)][c // 2 ** (N-1)] * 4 ** (N-1)
    r, c = r % 2 ** (N-1), c % 2 ** (N-1)
    N -= 1

print(lt)
