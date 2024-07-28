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
                2*(X+A[i])-A[i+1]-A[i-1]
            )
        else:
            D[i] = X
    elif A[i] == A[i+1]:
        if A[i-1] > A[i]:
            D[i] = min(
                A[i-1]-A[i]+X,
                2*(X+A[i])-A[i+1]-A[i-1]
            )
        else:
            D[i] = X
    elif abs(A[i-1]-A[i]) >= X and abs(A[i]-A[i+1]) >= X:
        D[i] = 0
    elif A[i-1] <= A[i]-X:
        D[i] = X-abs(A[i]-A[i+1])
    elif A[i+1] <= A[i]-X:
        D[i] = X-abs(A[i]-A[i-1])
    elif A[i-1] >= A[i]+X:
        if A[i] < A[i+1]:
            D[i] = A[i]+X-A[i+1]
        else:
            D[i] = max(A[i+1]+2*X-A[i-1], 0) + max(A[i+1]+X-A[i], 0)
    elif A[i+1] >= A[i]+X:
        if A[i] < A[i-1]:
            D[i] = A[i]+X-A[i-1]
        else:
            D[i] = max(A[i-1]+2*X-A[i+1], 0) + max(A[i-1]+X-A[i], 0)
    elif A[i-1] < A[i] < A[i+1]:
        D[i] = min(
            A[i+1]-A[i]+X,
            2*(X+A[i])-A[i+1]-A[i-1],
            3*X+2*A[i-1]-A[i+1]-A[i]
        )
    elif A[i-1] > A[i] > A[i+1]:
        D[i] = min(
            A[i-1]-A[i]+X,
            2*(X+A[i])-A[i+1]-A[i-1],
            3*X+2*A[i+1]-A[i-1]-A[i]
        )
    elif A[i] < A[i-1] and A[i] < A[i+1]:
        D[i] = min(
            max(A[i-1], A[i+1])-A[i]+X,
            2*(X+A[i])-A[i+1]-A[i-1]
        )
    else:
        D[i] = max(A[i-1], A[i+1])-A[i]+X

    D[i] = max(D[i], 0)
print(min(D))
