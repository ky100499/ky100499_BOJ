paper = [[0]*100 for _ in range(100)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    for dx in range(10):
        for dy in range(10):
            paper[x+dx][y+dy] = 1
print(sum(map(sum, paper)))
