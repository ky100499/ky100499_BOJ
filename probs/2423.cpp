#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

vector<ti> G[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    if (N%2 != M%2) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch; cin >> ch;
            if (ch == '/') {
                G[i][j].push_back({i+1, j+1, 1});
                G[i+1][j+1].push_back({i, j, 1});
                G[i+1][j].push_back({i, j+1, 0});
                G[i][j+1].push_back({i+1, j, 0});
            }
            else {
                G[i][j].push_back({i+1, j+1, 0});
                G[i+1][j+1].push_back({i, j, 0});
                G[i+1][j].push_back({i, j+1, 1});
                G[i][j+1].push_back({i+1, j, 1});
            }
        }
    }

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, 0, 0);
    vector<vector<int>> dist(N+1, vector<int>(M+1, INF)); dist[0][0] = 0;
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();

        if (dist[x][y] < d) continue;

        if (x == N && y == M) {
            cout << d << '\n';
            break;
        }

        for (auto [nx, ny, w] : G[x][y]) {
            if (d+w < dist[nx][ny]) {
                dist[nx][ny] = d+w;
                pq.emplace(d+w, nx, ny);
            }
        }
    }

    return 0;
}
