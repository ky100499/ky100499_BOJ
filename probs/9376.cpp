#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e8,
          MAX = 100;

char B[MAX+2][MAX+2];
int dist[3][MAX+2][MAX+2],
    mv[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}},
    H, W;

void dijkstra(int di, pi s)
{
    auto [x, y] = s;
    dist[di][x][y] = 0;

    deque<ti> q; q.emplace_back(0, x, y);
    while (!q.empty()) {
        auto [d, x, y] = q.front(); q.pop_front();

        if (dist[di][x][y] < d) continue;

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, H+2) && in(ny, 0, W+2) && B[nx][ny] != '*') {
                if (B[nx][ny] == '#' && dist[di][nx][ny] > d+1) {
                    dist[di][nx][ny] = d+1;
                    q.emplace_back(d+1, nx, ny);
                }
                else if (B[nx][ny] == '.' && dist[di][nx][ny] > d) {
                    dist[di][nx][ny] = d;
                    q.emplace_front(d, nx, ny);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        cin >> H >> W;
        vector<pi> start; start.emplace_back(0, 0);
        for (int i = 0 ; i < H+2; i++)
            for (int j = 0; j < W+2; j++)
                B[i][j] = '.';
        for (int i = 1 ; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> B[i][j];
                if (B[i][j] == '$') {
                    B[i][j] = '.';
                    start.emplace_back(i, j);
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < H+2; j++) {
                for (int k = 0; k < W+2; k++) {
                    dist[i][j][k] = INF;
                }
            }
            dijkstra(i, start[i]);
        }

        int ans = INF;
        for (int i = 0; i < H+2; i++) {
            for (int j = 0; j < W+2; j++) {
                if (B[i][j] == '*') continue;
                int tmp = B[i][j] == '#' ? -2 : 0;
                for (int k = 0; k < 3; k++) tmp += dist[k][i][j];
                ans = min(ans, tmp);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
