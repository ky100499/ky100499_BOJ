import sys
input = sys.stdin.readline

from collections import deque

N = int(input())
pic, pic2 = [], []
for _ in range(N):
    row = list(map(lambda x:x, input().strip()))
    pic.append(row[:])
    pic2.append(row[:])

normal = 0
for i, j in [(i, j) for i in range(N) for j in range(N)]:
    if pic[i][j] != 0:
        normal += 1
        color = pic[i][j]
        q = deque([(i, j)])
        visited = {}
        while q:
            x, y = q.popleft()
            if (x, y) in visited:
                continue
            visited[x, y] = 1
            pic[x][y] = 0

            if x>0 and pic[x-1][y] == color:
                q.append((x-1, y))
            if y>0 and pic[x][y-1] == color:
                q.append((x, y-1))
            if x+1<N and pic[x+1][y] == color:
                q.append((x+1, y))
            if y+1<N and pic[x][y+1] == color:
                q.append((x, y+1))

sakyak = 0
for i, j in [(i, j) for i in range(N) for j in range(N)]:
    if pic2[i][j] != 0:
        sakyak += 1
        color = pic2[i][j]
        if color in 'RG':
            color = 'RG'
        q = deque([(i, j)])
        visited = {}
        while q:
            x, y = q.popleft()
            if (x, y) in visited:
                continue
            visited[x, y] = 1
            pic2[x][y] = 0

            if x>0 and pic2[x-1][y] != 0 and pic2[x-1][y] in color:
                q.append((x-1, y))
            if y>0 and pic2[x][y-1] != 0 and pic2[x][y-1] in color:
                q.append((x, y-1))
            if x+1<N and pic2[x+1][y] != 0 and pic2[x+1][y] in color:
                q.append((x+1, y))
            if y+1<N and pic2[x][y+1] != 0 and pic2[x][y+1] in color:
                q.append((x, y+1))

print(f'{normal} {sakyak}')
