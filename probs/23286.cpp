#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 301,
          INF = 1e9;

int N, M, T;
map<int, int> G[MAX];
int dist[MAX][MAX];

void dijkstra(int s)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, f] = pq.top(); pq.pop();

        if (dist[s][f] < d) continue;

        for (auto [t, w] : G[f]) {
            int h = max(d, w);
            if (dist[s][t] > h) {
                dist[s][t] = h;
                pq.emplace(h, t);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M >> T;
    while (M--) {
        int u, v, h; cin >> u >> v >> h;
        if (G[u].find(v) == G[u].end()) G[u][v] = h;
        else G[u][v] = min(G[u][v], h);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = i == j ? 0 : INF;
        }
        dijkstra(i);
    }

    while (T--) {
        int s, e; cin >> s >> e;
        cout << (dist[s][e] == INF ? -1 : dist[s][e]) << '\n';
    }

    return 0;
}
