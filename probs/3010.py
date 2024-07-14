import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

B = [[-1]*7 for _ in range(7)]
for i in range(7):
    for j, v in enumerate(input().rstrip()):
        if v == '.':
            B[i][j] = 0
        elif v == 'o':
            B[i][j] = 1

cnt = 0
for i in range(7):
    for j in range(7):
        if B[i][j] != 1:
            continue
        for di, dj in [[-1,0],[0,-1],[1,0],[0,1]]:
            if 0 <= i+2*di < 7 and 0 <= j+2*dj < 7 and B[i+di][j+dj] == 1 and B[i+2*di][j+2*dj] == 0:
                cnt += 1
print(cnt)
