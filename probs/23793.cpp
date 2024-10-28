#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int INF = 2e9;

int N, M;
vector<map<int, int>> G;

int dijkstra(int from, int to, int ban)
{
    vector<int> dist(N+1, INF); dist[from] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, from});
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;

        if (s == to) return d;

        for (auto [t, w] : G[s]) {
            if (t == ban) continue;
            if (dist[t] > d+w) {
                dist[t] = d+w;
                pq.push({d+w, t});
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

    cin >> N >> M;
    G.resize(N+1);
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = w;
    }
    int x, y, z; cin >> x >> y >> z;

    int xy = dijkstra(x, y, -1), yz = dijkstra(y, z, -1), xz = dijkstra(x, z, y);
    cout << (xy != -1 && yz != -1 ? xy+yz : -1) << ' ' << xz;

    return 0;
}
