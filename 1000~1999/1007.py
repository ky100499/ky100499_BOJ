import sys
input = sys.stdin.readline

from itertools import combinations

T = int(input())

for _ in range(T):
    N = int(input())

    starts = list(combinations(range(N), N//2))
    starts = starts[:len(starts)//2]

    coords = []
    total = [0, 0]
    for _ in range(N):
        x, y = map(int, input().split())
        coords.append((x, y))
        total[0] += x
        total[1] += y

    ans = 1e6
    for p_st in starts:
        s = [0, 0]
        for i in p_st:
            s[0] += coords[i][0]
            s[1] += coords[i][1]
        dist = ((total[0] - 2 * s[0]) ** 2 + (total[1] - 2 * s[1]) ** 2) ** 0.5
        ans = min(ans, dist)

    print(ans)
