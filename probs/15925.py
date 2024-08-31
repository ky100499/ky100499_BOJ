import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N, M = map(int, input().split())
S = [list(map(int, input().split())) for _ in range(N)]

while True:
    update = False

    for i in range(N):
        cnt = 0
        for j in range(N):
            cnt += int(S[i][j] == M)
        if N > cnt > N//2:
            update = True
            for j in range(N):
                S[i][j] = M

    for i in range(N):
        cnt = 0
        for j in range(N):
            cnt += int(S[j][i] == M)
        if N > cnt > N//2:
            update = True
            for j in range(N):
                S[j][i] = M

    if not update:
        break

print(1 if sum(map(sum, S)) == N*N*M else 0)
