#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using qi = tuple<int, int, int, int>;

const int MAX = 1e3,
          INF = 1e9;

int B[MAX][MAX],
    dist[MAX][MAX][2],
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string ipt; cin >> ipt;
        for (int j = 0; j < M; j++) {
            B[i][j] = ipt[j]-'0';
        }
    }

    fill(&dist[0][0][0], &dist[N][0][0], INF);
    dist[0][0][0] = 1;

    int ans = -1;
    queue<qi> q; q.emplace(1, 0, 0, 0);
    while (!q.empty()) {
        auto [d, x, y, b] = q.front(); q.pop();

        if (d > dist[x][y][b]) continue;
        if (x == N-1 && y == M-1) {
            ans = d;
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M)) {
                if (!B[nx][ny] && dist[nx][ny][b] > d+1) {
                    dist[nx][ny][b] = d+1;
                    q.emplace(d+1, nx, ny, b);
                }
                else if (B[nx][ny] && !b && dist[nx][ny][1] > d+1) {
                    dist[nx][ny][1] = d+1;
                    q.emplace(d+1, nx, ny, 1);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
