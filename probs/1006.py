import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def solve(s):
    for i in range(s, N):
        dp[i][1] = dp[i][0]+1
        if e[0][i-1]+e[0][i] <= W:
            dp[i][1] = min(dp[i][1], dp[i-1][2]+1)

        dp[i][2] = dp[i][0]+1
        if e[1][i-1]+e[1][i] <= W:
            dp[i][2] = min(dp[i][2], dp[i-1][1]+1)

        dp[i+1][0] = min(dp[i][1], dp[i][2]) + 1
        if e[0][i]+e[1][i] <= W:
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]+1)
        if e[0][i-1]+e[0][i] <= W and e[1][i-1]+e[1][i] <= W:
            dp[i+1][0] = min(dp[i+1][0], dp[i-1][0]+2)

for i in range(int(input())):
    N, W = map(int, input().split())

    e = [list(map(int, input().split())) for _ in range(2)]

    if N == 1:
        print(2 if e[0][0]+e[1][0] > W else 1)
        continue

    ans = 2*N

    '''
        [0]
        X
        X

        [1]
        O
        X

        [2]
        X
        O
    '''

    dp = [[0]*3 for _ in range(N+1)]

    # 처음 끝 연결 X
    dp[0] = [0, 1, 1]
    dp[1][0] = 2 if e[0][0]+e[1][0] > W else 1

    solve(1)

    ans = min(ans, dp[N][0])

    # 1행만 연결
    if e[0][-1]+e[0][0] <= W:
        dp[1] = [
            1,
            2,
            1 + int(e[1][0] + e[1][1] > W),
        ]
        dp[2][0] = min(dp[1][1], dp[1][2])+1 if e[0][1]+e[1][1] > W else dp[1][0]+1

        solve(2)

        ans = min(ans, dp[N-1][2]+1)

    # 2행만 연결
    if e[1][-1]+e[1][0] <= W:
        dp[1] = [
            1,
            1 + int(e[0][0] + e[0][1] > W),
            2,
        ]
        dp[2][0] = min(dp[1][1], dp[1][2])+1 if e[0][1]+e[1][1] > W else dp[1][0]+1

        solve(2)

        ans = min(ans, dp[N-1][1]+1)

    # 1 2행 모두 연결
    if e[0][-1]+e[0][0] <= W and e[1][-1]+e[1][0] <= W:
        dp[1] = [
            0,
            1,
            1,
        ]
        dp[2][0] = min(dp[1][1], dp[1][2])+1 if e[0][1]+e[1][1] > W else dp[1][0]+1

        solve(2)

        ans = min(ans, dp[N-1][0]+2)

    print(ans)
