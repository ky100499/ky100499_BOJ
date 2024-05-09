import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

R, C = map(int, input().split())
img = [list(map(int, input().split())) for _ in range(R)]
T = int(input())

cnt = 0
for r in range(R-2):
    for c in range(C-2):
        ft = []
        for (i, j) in [(i, j) for i in range(3) for j in range(3)]:
            ft.append(img[r+i][c+j])
        ft.sort()
        if ft[4] >= T:
            cnt += 1
print(cnt)
