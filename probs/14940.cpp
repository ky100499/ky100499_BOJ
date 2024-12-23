#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 1000;

int B[MAX][MAX],
    dist[MAX][MAX],
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    queue<pi> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
            dist[i][j] = -1;

            if (B[i][j] == 2) {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M) && B[nx][ny] && (dist[nx][ny] > dist[x][y]+1 || dist[nx][ny] == -1)) {
                dist[nx][ny] = dist[x][y]+1;
                q.emplace(nx, ny);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << dist[i][j] * B[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
