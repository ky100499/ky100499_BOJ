import sys
sys.setrecursionlimit(1000)

def bt(x, y):
    if x == N:
        print(*map(lambda x: ' '.join(map(str, x)), B), sep='\n')
        exit(0)

    for i in range(D):
        B[x][y] = i
        ok = True
        for j in range(y):
            if B[x][y] == B[x][j]:
                ok = False
                break
        for j in range(x):
            if B[x][y] == B[j][y]:
                ok = False
                break
        if ok:
            bt(x+(y+1)//N, max((y+1)%N, M))

N, D = map(int, input().split())
M = N-D+1

B = [[0]*N for _ in range(N)]
for i in range(M):
    for j in range(M, N):
        B[i][j] = B[j][i] = j-M+1
bt(M, M)
