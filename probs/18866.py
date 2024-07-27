import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e10)

N = int(input())
U, V = [], []
for _ in range(N):
    u, v = map(int, input().split())
    U.append(u)
    V.append(v)

# Y: 젊은 날, [최소 행복, 최대 피로]
# O: 늙은 날, [최대 행복, 최소 피로] (역순)
# 젊은 날 조건: k일에서 Y[k][0] > O[k+1][0] and Y[k][1] < O[k+1][1]
Y, O = [[INF, 0] for _ in range(N+2)], [[0, INF] for _ in range(N+2)]
for i in range(1, N+1):
    u, v = U[i-1], V[i-1]
    if u:
        Y[i][0] = min(Y[i-1][0], u)
    else:
        Y[i][0] = Y[i-1][0]
    if v:
        Y[i][1] = max(Y[i-1][1], v)
    else:
        Y[i][1] = Y[i-1][1]
for i in range(N, 0, -1):
    u, v = U[i-1], V[i-1]
    if u:
        O[i][0] = max(O[i+1][0], u)
    else:
        O[i][0] = O[i+1][0]
    if v:
        O[i][1] = min(O[i+1][1], v)
    else:
        O[i][1] = O[i+1][1]

for k in range(N-1, 0, -1):
    if Y[k][0] > O[k+1][0] and Y[k][1] < O[k+1][1]:
        print(k)
        break
else:
    print(-1)
