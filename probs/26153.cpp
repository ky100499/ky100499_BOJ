#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

const int MAX = 50;

int N, M,
    W[MAX][MAX], V[MAX][MAX],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int solve(int x, int y, int d, int p)
{
    int ret = 0;

    if (p) {
        int nx = x+mv[d][0], ny = y+mv[d][1];
        if (in(nx, 0, N) && in(ny, 0, M) && !V[nx][ny]) {
            V[nx][ny] = 1;
            ret = max(ret, solve(nx, ny, d, p-1));
            V[nx][ny] = 0;
        }
    }
    if (p > 1) {
        for (int i = 1; i < 4; i += 2) {
            int nd = (d+i)%4;
            int nx = x+mv[nd][0], ny = y+mv[nd][1];

            if (in(nx, 0, N) && in(ny, 0, M) && !V[nx][ny]) {
                V[nx][ny] = 1;
                ret = max(ret, solve(nx, ny, nd, p-2));
                V[nx][ny] = 0;
            }
        }
    }

    return W[x][y] + ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> W[i][j];
    int x, y, p; cin >> x >> y >> p;

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        memset(V, 0, sizeof V); V[x][y] = 1;
        ans = max(ans, solve(x, y, i, p));
    }

    cout << ans << '\n';

    return 0;
}
