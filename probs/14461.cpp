#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ti = tuple<ll, int, int, int>;

ll INF = 1e18;

int mv[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0},
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, T; cin >> N >> T;
    vector<vector<int>> G(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> G[i][j];

    vector<vector<vector<ll>>> dist(N, vector<vector<ll>>(N, vector<ll>(3, INF))); dist[0][0][0] = 0;
    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.push({0, 0, 0, 0});
    while (!pq.empty()) {
        auto [d, x, y, c] = pq.top(); pq.pop();

        if (x==N-1 && y==N-1) {
            cout << d << '\n';
            break;
        }

        if (dist[x][y][c%3] < d) continue;

        for (auto m : mv) {
            int nx = x+m[0], ny = y+m[1];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                ll nd = d + T + ((c+1)%3 ? 0 : G[nx][ny]);
                if (dist[nx][ny][(c+1)%3] > nd) {
                    dist[nx][ny][(c+1)%3] = nd;
                    pq.push({nd, nx, ny, c+1});
                }
            }
        }
    }

    return 0;
}
