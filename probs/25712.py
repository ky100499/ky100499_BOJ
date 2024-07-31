import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
A = list(map(int, input().split()))

col = list(map(int, input().split()))
for i in range(M-1):
    col2 = list(map(int, input().split()))

    l = len(col)
    nc = []
    x, y = 0, 0
    while x < l and y < A[i+1]:
        if col[x] > col2[y+1]:
            y += 2
        elif col[x+1] < col2[y]:
            x += 2
        else:
            nc += col2[y:y+2]
            y += 2
    col = nc

if col:
    print('YES')
else:
    print('NO')
