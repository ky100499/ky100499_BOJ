import sys
input = sys.stdin.readline

N = int(input())
A = list(enumerate(map(int, input().split())))
s = sorted(A, key=lambda x: x[1])
B = [(A[i][0], s[i][0]) for i in range(N)]
B.sort(key=lambda x: x[1])
print(' '.join(map(lambda x: str(x[0]), B)))
