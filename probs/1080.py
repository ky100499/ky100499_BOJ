import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def matsum(X):
    return sum(map(sum, X))

N, M = map(int, input().split())
A = []
for _ in range(N):
    A.append(list(map(int, input().rstrip())))
for i in range(N):
    for j, b in enumerate(map(int, input().rstrip())):
        A[i][j] = A[i][j] ^ b

ans = 0
for i in range(0, N-2):
    for j in range(0, M-2):
        if A[i][j]:
            ans += 1
            for di in range(3):
                for dj in range(3):
                    A[i+di][j+dj] ^= 1
print(-1 if matsum(A) else ans)
