#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 200'001,
          INF = 1e9;

int dist[MAX],
    V[MAX];
map<int, int> G[MAX];

int dijkstra(int S, int E, int save)
{
    fill(dist, dist+MAX, INF); dist[S] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, S);
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;
        if (s == E) break;

        for (auto [t, w] : G[s]) {
            if (!V[t] && dist[t] > d+w) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    if (save) {
        int u = E;
        while (u != S) {
            for (auto [v, w] : G[u]) {
                if (dist[u] == dist[v]+w) {
                    V[v] = 1;
                    u = v;
                    break;
                }
            }
        }
    }

    return dist[E];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    int S, E; cin >> S >> E;

    memset(V, 0, sizeof V);
    cout << dijkstra(E, S, 1) + dijkstra(E, S, 0) << '\n';

    return 0;
}
