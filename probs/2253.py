import sys
input = sys.stdin.readline

input = open('input.txt', 'r').readline

INF = int(1e9)

N, M = map(int, input().split())
B = set(int(input()) for _ in range(M))

# dp[i][j] -> i번째 칸에 j칸 점프로 도달
# 매번 점프 간격을 증가시킬 때 N번째 칸에서의 간격
# x(x+1)/2 > N
# 대충 잡으면 x < sqrt(2N)
dp = [[INF]*(int((2*N)**0.5)+1) for _ in range(N+1)]
dp[1][0] = 0

for i in range(1, N):
    for j in range(int((2*i)**0.5)+1):
        if dp[i][j] != INF:
            for s in (j-1,j,j+1):
                if i < i+s <= N and i+s not in B:
                    dp[i+s][s] = min(dp[i+s][s], dp[i][j]+1)
if (ans := min(dp[N])) == INF:
    print(-1)
else:
    print(ans)
