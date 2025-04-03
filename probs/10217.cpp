#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

vector<ti> G[101];
int dist[101][10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, M, K; cin >> N >> M >> K;
        while (K--) {
            int u, v, c, d; cin >> u >> v >> c >> d;
            G[u].emplace_back(v, c, d);
        }
        for (int i = 1; i <= N; i++) sort(G[i].begin(), G[i].end());

        fill(&dist[0][0], &dist[101][0], INF); dist[1][0] = 0;
        priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, 0, 1);
        while (!pq.empty()) {
            auto [d, c, s] = pq.top(); pq.pop();

            if (dist[s][c] < d) continue;

            for (auto [t, tc, td] : G[s]) {
                int nc = c+tc, nd = d+td;
                if (nc <= M && nd < dist[t][nc]) {
                    for (int i = nc; i <= M && nd < dist[t][i]; i++) {
                        dist[t][i] = nd;
                    }
                    pq.emplace(nd, nc, t);
                }
            }
        }

        if (dist[N][M] == INF) cout << "Poor KCM\n";
        else cout << dist[N][M] << '\n';
    }

    return 0;
}
