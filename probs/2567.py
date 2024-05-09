import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

paper = [[0]*101 for _ in range(101)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    for i in range(10):
        for j in range(10):
            paper[x+i][y+j] = 1

edgeX = [[0]*100 for _ in range(100)]
edgeY = [[0]*100 for _ in range(100)]
for i in range(100):
    for j in range(100):
        edgeX[i][j] = paper[i+1][j] ^ paper[i][j]
        edgeY[i][j] = paper[i][j+1] ^ paper[i][j]
print(sum(map(sum, edgeX)) + sum(map(sum, edgeY)))
