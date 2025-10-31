#include <bits/stdc++.h>

#define in(x, a, b) (a < x && x <= b)

using namespace std;
using qi = tuple<int, int, int, int>;

const int INF = 1e9;

int A[101][101], D[101][101][5],
    mv[5][2] = { {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} },
    R[5] = { 0, 3, 4, 2, 1 },
    L[5] = { 0, 4, 3, 1, 2 };

int rotate(int d, int r)
{
    return (r ? R : L)[d];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];
    int sx, sy, sd, tx, ty, td; cin >> sx >> sy >> sd >> tx >> ty >> td;

    queue<qi> q; q.emplace(sx, sy, sd, 0);
    fill(&D[0][0][0], &D[N+1][0][0], INF); D[sx][sy][sd] = 0;
    while (!q.empty()) {
        auto [x, y, d, w] = q.front(); q.pop();

        if (x == tx && y == ty && d == td) break;
        if (D[x][y][d] < w) continue;

        auto [dx, dy] = mv[d];
        int nx = x, ny = y;
        for (int i = 1; i <= 3; i++) {
            nx += dx, ny += dy;
            if (!in(nx, 0, N) || !in(ny, 0, M) || A[nx][ny]) break;
            if (D[nx][ny][d] > w+1) {
                D[nx][ny][d] = w+1;
                q.emplace(nx, ny, d, w+1);
            }
        }

        for (int i = 0; i < 2; i++) {
            int nd = rotate(d, i);
            if (D[x][y][nd] > w+1) {
                D[x][y][nd] = w+1;
                q.emplace(x, y, nd, w+1);
            }
        }
    }

    cout << D[tx][ty][td] << '\n';

    return 0;
}
