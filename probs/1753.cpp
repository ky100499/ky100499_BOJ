#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 2e4,
          INF = 1e9;

int dist[MAX+1];
map<int, int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int V, E, K; cin >> V >> E >> K;
    while (E--) {
        int u, v, w; cin >> u >> v >> w;
        if (G[u].find(v) == G[u].end()) G[u][v] = w;
        else G[u][v] = min(G[u][v], w);
    }

    fill(dist, dist+V+1, INF); dist[K] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, K);
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;

        for (auto [t, w] : G[s]) {
            if (dist[t] > d+w) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
