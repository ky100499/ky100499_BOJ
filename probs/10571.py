import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

for _ in range(int(input())):
    N = int(input())
    D = [[0,0] for _ in range(N)]
    dp = [1]*N
    for i in range(N):
        w, c = map(float, input().split())
        D[i] = [w, c]
        for j in range(i):
            if D[j][0] < D[i][0] and D[j][1] > D[i][1]:
                dp[i] = max(dp[i], dp[j]+1)
    print(max(dp))
