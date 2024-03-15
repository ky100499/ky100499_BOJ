def cut(paper, lt, size):
    s = 0
    for i, j in [(lt[0]+i, lt[1]+j) for i in range(size) for j in range(size)]:
        s += paper[i][j]
    if s == 0:
        return (1, 0)
    elif s == size**2:
        return (0, 1)
    else:
        ret = (0, 0)
        for x, y in [[0, 0], [size//2, 0], [0, size//2], [size//2, size//2]]:
            res = cut(paper, (lt[0]+x, lt[1]+y), size//2)
            ret = (ret[0] + res[0], ret[1] + res[1])
        return ret

N = int(input())
paper = []
for _ in range(N):
    paper.append(list(map(int, input().split())))
print('\n'.join(map(str, cut(paper, (0, 0), N))))
