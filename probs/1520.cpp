#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

const int MAX = 500;

int N, M,
    A[MAX][MAX],
    dp[MAX][MAX],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int dfs(int x, int y)
{
    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M) && A[x][y] > A[nx][ny]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    memset(dp, -1, sizeof dp); dp[N-1][M-1] = 1;
    cout << dfs(0, 0) << '\n';

    return 0;
}
