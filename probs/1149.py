import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

N = int(input())
cost = [list(map(int, input().split()))for _ in range(N)]

min_cost = [[10000]*3 for _ in range(N)]
min_cost[0] = cost[0][:]
for i in range(1, N):
    min_cost[i][0] = min(min_cost[i-1][1], min_cost[i-1][2]) + cost[i][0]
    min_cost[i][1] = min(min_cost[i-1][2], min_cost[i-1][0]) + cost[i][1]
    min_cost[i][2] = min(min_cost[i-1][0], min_cost[i-1][1]) + cost[i][2]

print(min(min_cost[N-1]))
