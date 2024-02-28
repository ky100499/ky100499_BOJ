T = int(input())

for i in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    cnt = 0
    for j in range(n):
        cx, cy, r = map(int, input().split())
        cnt += 1 if (
            (x1 - cx) ** 2 + (y1 - cy) ** 2 < r ** 2
        ) ^ (
            (x2 - cx) ** 2 + (y2 - cy) ** 2 < r ** 2
        ) else 0

    print(cnt)
