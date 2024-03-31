N, K = map(int, input().split())
A = list(map(int, input().split()))

swaps = 0
for i in reversed(range(N)):
    for j in range(i):
        if A[j] > A[j+1]:
            A[j], A[j+1] = A[j+1], A[j]
            swaps += 1
            if swaps == K:
                print(A[j], A[j+1])
if swaps < K:
    print(-1)
