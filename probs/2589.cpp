#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;

const int INF = 1e9;

char B[50][50];
int mv[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (B[i][j] == 'W') continue;

            vector<vector<int>> dist(N, vector<int>(M, INF));
            dist[i][j] = 0;
            queue<pi> q({{i, j}});
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : mv) {
                    int nx = x+dx, ny = y+dy;
                    if (in(nx, 0, N) && in(ny, 0, M) && B[nx][ny] == 'L' && dist[nx][ny] > dist[x][y]+1) {
                        dist[nx][ny] = dist[x][y]+1;
                        ans = max(ans, dist[nx][ny]);
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
