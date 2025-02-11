#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 502,
          INF = 1e9;

char B[MAX][MAX];
int W[MAX][MAX],
    dist[MAX][MAX],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    memset(W, 0, sizeof W);
    deque<ti> q;
    fill(&dist[1][0], &dist[N+1][0], INF);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> B[i][j];
            if (B[i][j] == '#') {
                for (auto [di, dj] : mv) {
                    W[i+di][j+dj] = 1;
                }
            }
            else if (B[i][j] == 'S') {
                q.emplace_back(0, i, j);
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [d, x, y] = q.front(); q.pop_front();

        if (dist[x][y] < d) continue;
        if (B[x][y] == 'E') {
            cout << d << '\n';
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (B[nx][ny] != '#') {
                if (W[x][y] && W[nx][ny] && d < dist[nx][ny]) {
                    dist[nx][ny] = d;
                    q.emplace_front(d, nx, ny);
                }
                else if (d+1 < dist[nx][ny]) {
                    dist[nx][ny] = d+1;
                    q.emplace_back(d+1, nx, ny);
                }
            }
        }
    }

    return 0;
}
