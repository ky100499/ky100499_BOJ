import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

def dfs(s, v, p):
    # 미방문 상태거나 더 싼 가격인 경우 갱신
    if dp[s][v] == -1 or price[s] > p:
        price[s] = p
        dp[s][v] = 0
        # 그림을 파는 경우
        for i in range(N):
            if v & (1<<i) == 0 and M[s][i] >= p:
                dp[s][v] = max(dp[s][v], 1+dfs(i, v | (1<<i), M[s][i]))

    return dp[s][v]


N = int(input())
M = [list(map(int, input().rstrip())) for _ in range(N)]

# price[i] -> i번째 아티스트가 구매한 그림의 최소 가격
# dp[i][v] -> i번째 아티스트가 v 상태로 그림을 가지고 있을 때 이후에 그림을 소유할 수 있는 사람의 수
price = [9]*N
dp = [[-1]*(1<<N) for _ in range(N)]
print(1+dfs(0, 1, 0))
