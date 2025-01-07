#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 5000,
          INF = 1e9;

int dist[MAX+1], H[MAX], C[MAX];
map<int, int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int V, E; cin >> V >> E;
    while (E--) {
        int u, v, w; cin >> u >> v >> w;
        if (G[u].find(v) == G[u].end()) G[u][v] = G[v][u] = w;
        else G[u][v] = G[v][u] = min(G[u][v], w);
    }

    fill(dist, dist+V+1, INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    int p, q; cin >> p >> q;
    for (int i = 0; i < p; i++) cin >> H[i];
    sort(H, H+p);
    for (int i = 0; i < q; i++) {
        cin >> C[i];
        dist[C[i]] = 0;
        pq.emplace(0, C[i]);
    }

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

    int ans, d = INF;
    for (int i = 0; i < p; i++) {
        if (dist[H[i]] < d) {
            d = dist[H[i]];
            ans = H[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
