T = int(input())

for i in range(T):
    x1, y1, r1, x2, y2, r2 = tuple(map(int, input().split()))

    dist = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

    if dist == 0:
        print(-1 if r1 == r2 else 0)
    else:
        lens = sorted([dist, r1, r2])
        if lens[2] > lens[0] + lens[1]:
            print(0)
        elif lens[2] == lens[0] + lens[1]:
            print(1)
        else:
            print(2)
