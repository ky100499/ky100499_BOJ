import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

dp = [[-1]*5, [-1]*5]
cur = 0

for i, n in enumerate(map(int, input().split())):
    if n == 0:
        ans = int(1e9)
        for a in dp[(i-1)%2]:
            if a != -1:
                ans = min(ans, a)
        print(ans)
        break

    dp[i%2] = [-1]*5

    if i == 0:
        cur = n
        dp[0][0] = 2
    elif cur == n:
        # 이전에 누른 발과 동일
        dp[i%2] = list(map(lambda x: -1 if x == -1 else x+1, dp[(i-1)%2]))
    else:
        # 이전에 누른 발을 이동하여 누르는 경우
        # 발이 겹치는 경우는 아래에서 덮어씌워짐
        add = 4 if abs(cur - n) == 2 else 3
        dp[i%2] = list(map(lambda x: -1 if x == -1 else x+add, dp[(i-1)%2]))

        # 이전에 누르지 않은 발로 누르는 경우
        if dp[(i-1)%2][n] != -1:
            dp[i%2][cur] = dp[(i-1)%2][n] + 1

        # 이전에 누르지 않은 발을 이동하여 누르는 경우
        for j in range(5):
            if j == n or j == cur:
                continue
            add = 4 if abs(j - n) == 2 else 3
            if j == 0:
                add = 2
            if dp[(i-1)%2][j] != -1:
                if dp[i%2][cur] == -1:
                    dp[i%2][cur] = dp[(i-1)%2][j] + add
                else:
                    dp[i%2][cur] = min(dp[i%2][cur], dp[(i-1)%2][j] + add)

        cur = n
