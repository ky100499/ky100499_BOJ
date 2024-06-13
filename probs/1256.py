import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M, K = map(int, input().split())

pt = [[0]*(N+M+1) for _ in range(N+M+1)]
for i in range(N+M+1):
    pt[i][0] = 1
    for j in range(1, i+1):
        pt[i][j] = pt[i-1][j]+pt[i-1][j-1]

if K > pt[N+M][N]:
    print(-1)
else:
    ans = ''
    while N*M != 0:
        if (A := pt[N+M-1][M]) >= K:
            ans += 'a'
            N -= 1
        else:
            ans += 'z'
            M -= 1
            K -= A
    else:
        ans += 'z'*M+'a'*N
    print(ans)
