#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using qi = tuple<int, int, int, int>;

const int MAX = 100,
          INF = 1e9;

int B[MAX][MAX],
    dist[MAX][MAX][2],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, T; cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    fill(&dist[0][0][0], &dist[N][0][0], INF); dist[0][0][0] = 0;
    queue<qi> q; q.emplace(0, 0, 0, 0);
    int ans = -1;
    while (!q.empty()) {
        auto [t, x, y, g] = q.front(); q.pop();

        if (x == N-1 && y == M-1) {
            ans = t;
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M) && (g || B[nx][ny] != 1)) {
                int ng = g || B[nx][ny] == 2;
                if (dist[nx][ny][ng] > t+1 && t < T) {
                    dist[nx][ny][ng] = t+1;
                    q.emplace(t+1, nx, ny, ng);
                }
            }
        }
    }

    if (ans == -1) cout << "Fail\n";
    else cout << ans << '\n';

    return 0;
}
