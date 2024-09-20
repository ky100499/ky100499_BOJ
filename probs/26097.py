import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
B = [[]]+[[-1]+list(map(int, input().split())) for _ in range(N)]

if N%2 & M%2 or sum(map(lambda x: x.count(0), B)) % 2:
    print(-1)
else:
    elim = False
    for i in range(1, N+1):
        for j in range(1, M+1):
            for di, dj in ((1,0),(0,1)):
                ni, nj = i+di, j+dj
                if 0 < ni <= N and 0 < nj <= M and B[ni][nj] == B[i][j]:
                    print(1)
                    print(i, j, ni, nj)
                    B[i][j] = B[ni][nj] = -1
                    elim = True
                    break
            if elim:
                break
        if elim:
            break


    if elim:
        ans = [[], []]
        for i in range(1, N+1):
            for j in range(1, M+1):
                if B[i][j] != -1:
                    ans[B[i][j]].append((i, j))
        for a in ans:
            for i in range(len(a)//2):
                print(*a[2*i], *a[2*i+1])
    else:
        print(-1)
