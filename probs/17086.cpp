#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ti = tuple<int, int, int>;

int dist[50][50],
    mv[8][2] = {
        {0,-1},
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
    };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    fill(&dist[0][0], &dist[N][0], 1e9);
    queue<ti> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s; cin >> s;
            if (s) {
                dist[i][j] = 0;
                q.emplace(i, j, 0);
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        if (dist[x][y] < d) continue;

        ans = max(ans, d);

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M) && dist[nx][ny] > d+1) {
                dist[nx][ny] = d+1;
                q.emplace(nx, ny, d+1);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
