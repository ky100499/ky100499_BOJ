import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e10)

N = int(input())
A, B = [], []
for _ in range(N):
    u, v = map(int, input().split())
    A.append(u)
    B.append(v)

U, V = ([[0, INF] for _ in range(N+1)] for _ in range(2))
for i in range(1, N+1):
    u, v = A[i-1], B[i-1]
    if u:
        U[i][0] = max(U[i-1][0], u)
    else:
        U[i][0] = U[i-1][0]
    if v:
        V[i][0] = max(V[i-1][0], v)
    else:
        V[i][0] = V[i-1][0]
for i in range(N-1, -1, -1):
    u, v = A[i], B[i]
    if u:
        U[i][1] = min(U[i+1][1], u)
    else:
        U[i][1] = U[i-1][1]
    if v:
        V[i][1] = min(V[i+1][1], v)
    else:
        V[i][1] = V[i-1][1]

if sum(A) == 0 and sum(B) == 0:
    print(N-1)
else:
    ans = -1
    for k in range(1, N):
        if (A[k-1] == 0 or U[k][0] > U[k-1][1]) and (B[k-1] == 0 or V[k][0] < V[k][1]):
            ans = k
        else:
            break
    print(ans)
