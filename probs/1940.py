import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
M = int(input())
mat = list(map(int, input().split()))

mat.sort()

cnt = 0
i, j = 0, N-1
while i < j:
    if mat[i] + mat[j] > M:
        j -= 1
    elif mat[i] + mat[j] < M:
        i += 1
    else:
        cnt += 1
        i += 1
        j -= 1
print(cnt)
