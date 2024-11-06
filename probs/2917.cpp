#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

int dist[500][500] = {{0,},},
    cost[500][500] = {{0,},},
    mv[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    queue<pi> T;
    pi V, J;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INF;

            char ipt; cin >> ipt;
            if (ipt == 'V') V = {i, j};
            else if (ipt == 'J') J = {i, j};
            else if (ipt == '+') { T.push({i, j}); dist[i][j] = 0; }

        }
    }

    while (!T.empty()) {
        auto [x, y] = T.front(); T.pop();
        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && dist[nx][ny] > dist[x][y]+1) {
                dist[nx][ny] = dist[x][y]+1;
                T.push({nx, ny});
            }
        }
    }

    priority_queue<ti> pq; pq.push({cost[V.first][V.second] = dist[V.first][V.second], V.first, V.second});
    while (!pq.empty()) {
        auto [c, x, y] = pq.top(); pq.pop();

        if (c < cost[x][y]) continue;

        if (x == J.first && y == J.second) break;

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && cost[nx][ny] < min(dist[x][y], cost[x][y])) {
                cost[nx][ny] = min(dist[x][y], cost[x][y]);
                pq.push({cost[nx][ny], nx, ny});
            }
        }
    }

    cout << cost[J.first][J.second] << '\n';

    return 0;
}
