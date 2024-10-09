#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, A, B, C; cin >> N >> M >> A >> B >> C;
    vector<map<int, int>> G(N+1);
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.push({0, A, 0});
    vector<vector<int>> dist(N+1, vector<int>(C+1, INF)); dist[0] = vector<int>(C+1, 0);
    while (!pq.empty()) {
        auto [d, s, c] = pq.top(); pq.pop();

        if (s == B) break;

        if (dist[s][c] < d) continue;

        for (auto [t, tc] : G[s]) {
            int nc = c+tc, nd = max(d, tc);
            if (nc <= C && dist[t][nc] > nd) {
                for (int i = nc; i <= C; i++) {
                    dist[t][i] = nd;
                }
                pq.push({nd, t, nc});
            }
        }
    }

    cout << (dist[B][C] == INF ? -1 : dist[B][C]) << '\n';

    return 0;
}
