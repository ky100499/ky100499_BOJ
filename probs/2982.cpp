#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1001,
          INF = 1e9;

int gd[MAX],
    gdtime[MAX] = {},
    dist[MAX];
map<int, int> adj[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    int A, B, K, G; cin >> A >> B >> K >> G;
    for (int i = 0; i < G; i++) cin >> gd[i]; gd[G] = -1;
    while (M--) {
        int u, v, l; cin >> u >> v >> l;
        adj[u][v] = adj[v][u] = l;
    }
    for (int i = 0; i < G-1; i++)
        gdtime[i+1] = gdtime[i] + adj[gd[i]][gd[i+1]];

    for (int i = 0; i <= N; i++) dist[i] = INF; dist[A] = K;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(K, A);
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;
        if (s == B) {
            cout << d-K << '\n';
            break;
        }

        for (auto [t, w] : adj[s]) {
            int idx = upper_bound(gdtime, gdtime+G, d) - gdtime;
            int u = gd[idx-1], v = gd[idx];
            int nd = (s == u && t == v || s == v && t == u) ? gdtime[idx]+w : d+w;

            if (dist[t] > nd) {
                dist[t] = nd;
                pq.emplace(nd, t);
            }
        }
    }

    return 0;
}
