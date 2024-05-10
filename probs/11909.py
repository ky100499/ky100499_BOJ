import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

cost = [[0]*N for _ in range(N)]
for i in range(1, N):
    cost[0][i] = cost[0][i-1]
    if arr[0][i-1] <= arr[0][i]:
        cost[0][i] += arr[0][i] - arr[0][i-1] + 1

    cost[i][0] = cost[i-1][0]
    if arr[i-1][0] <= arr[i][0]:
        cost[i][0] += arr[i][0] - arr[i-1][0] + 1

for i in range(1, N):
    for j in range(1, N):
        l, t = cost[i][j-1], cost[i-1][j]

        if arr[i][j-1] <= arr[i][j]:
            l += arr[i][j] - arr[i][j-1] + 1
        if arr[i-1][j] <= arr[i][j]:
            t += arr[i][j] - arr[i-1][j] + 1

        cost[i][j] = min(l, t)

print(cost[-1][-1])
