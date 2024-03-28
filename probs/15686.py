import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

from itertools import combinations as c

N, M = map(int, input().split())
houses = []
chickens = []
city = [list(map(int, input().split())) for _ in range(N)]
for i, j in [(i, j) for i in range(N) for j in range(N)]:
    if city[i][j] == 1:
        houses.append((i, j))
    elif city[i][j] == 2:
        chickens.append((i, j))

distances = []
for ci, cj in chickens:
    distance = []
    for hi, hj in houses:
        distance.append(abs(ci-hi) + abs(cj-hj))
    distances.append(distance)

ans = 10**8
for dists in c(distances, M):
    ch_dist = [10**8] * len(houses)
    for dist in dists:
        for i, d in enumerate(dist):
            ch_dist[i] = min(ch_dist[i], d)
    ans = min(ans, sum(ch_dist))
print(ans)
