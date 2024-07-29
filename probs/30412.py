import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e10)

N, X = map(int, input().split())
A = list(map(int, input().split()))

D = [INF]*N
D[0] = max(X - abs(A[0] - A[1]), 0)
D[-1] = max(X - abs(A[-1] - A[-2]), 0)
for i in range(1, N-1):
    if A[i-1] == A[i] == A[i+1]:
        D[i] = X
    elif A[i-1] == A[i]:
        if A[i] < A[i+1]:
            D[i] = min(
                A[i+1]-A[i]+X,
                X+max(A[i]+X-A[i+1], 0)
            )
        else:
            D[i] = X
    elif A[i] == A[i+1]:
        if A[i-1] > A[i]:
            D[i] = min(
                A[i-1]-A[i]+X,
                X+max(A[i]+X-A[i-1], 0)
            )
        else:
            D[i] = X
    elif A[i] < A[i-1] and A[i] < A[i+1]:
        D[i] = max(A[i]+X-A[i-1], 0) + max(A[i]+X-A[i+1], 0)
    elif A[i] > A[i-1] and A[i] > A[i+1]:
        D[i] = max(max(A[i-1], A[i+1])+X-A[i], 0)
    elif A[i-1] < A[i] < A[i+1]:
        D[i] = max(A[i-1]+X-A[i], 0) + max(max(A[i], A[i-1]+X)+X-A[i+1], 0)
    elif A[i-1] > A[i] > A[i+1]:
        D[i] = max(A[i+1]+X-A[i], 0) + max(max(A[i], A[i+1]+X)+X-A[i-1], 0)
    else:
        raise FileNotFoundError
print(min(D))
