#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using qi = tuple<int, int, int, int>;

const int MAX = 101,
          INF = 1e9;

int dist[MAX][MAX][3],
    B[MAX][MAX],
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} },
    go[3][4] = { {1,1,1,1}, {1,0,1,0}, {0,1,0,1} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, sx, sy, ex, ey; cin >> N >> M >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> B[i][j];
            for (int k = 0; k < 3; k++) dist[i][j][k] = INF;
        }
    }

    priority_queue<qi, vector<qi>, greater<qi>> pq; pq.emplace(0, 1, sx, sy);
    dist[sx][sy][1] = 0;
    int ans = -1;
    while (!pq.empty()) {
        auto [d, k, x, y] = pq.top(); pq.pop();

        if (dist[x][y][k] < d) continue;
        if (x == ex && y == ey) {
            ans = d;
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (!go[k][i]) continue;
            int nx = x+mv[i][0], ny = y+mv[i][1], nk = (k+1)%3;
            if (in(nx, 1, N+1) && in(ny, 1, M+1) && B[nx][ny] != -1 && dist[nx][ny][nk] > d+B[nx][ny]) {
                dist[nx][ny][nk] = d+B[nx][ny];
                pq.emplace(d+B[nx][ny], nk, nx, ny);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
