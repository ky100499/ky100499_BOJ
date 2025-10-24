#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, int>;

const int MAX = 1e5+1;
const ll  INF = 2e18;

ll D1[MAX], D2[MAX], dist[2*MAX];
map<int, ll> G[2*MAX];

ll dijkstra(int S, int T, int N)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, S);
    fill(dist, dist+N+1, INF); dist[S] = 0;
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (d > 1e18) break;
        if (s == T) return d;
        if (d > dist[s]) continue;

        for (auto [t, w] : G[s]) {
            if (d+w < dist[t]) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M; cin >> N >> M;
        for (int i = 1; i <= N; i++) G[i].clear();
        while (M--) {
            int u, v; ll w; cin >> u >> v >> w;

            if (w < 0) {
                ll x = D1[-w];
                if (x != -1) {
                    if (G[u].find(v) == G[u].end()) G[u][v] = x;
                    else G[u][v] = min(G[u][v], x);
                }

                x = D2[-w];
                if (x != -1) {
                    if (G[v].find(u) == G[v].end()) G[v][u] = x;
                    else G[v][u] = min(G[v][u], x);
                }
            }
            else {
                if (G[u].find(v) == G[u].end()) G[u][v] = w;
                else G[u][v] = min(G[u][v], w);
            }
        }

        D1[t] = dijkstra(1, 2, N);
        D2[t] = dijkstra(2, 1, N);
    }

    cout << D1[T] << '\n';

    return 0;
}
