#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int INF = 1e9;

int V;
vector<map<int, int>> G;

vector<int> dijkstra(int from)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, from});
    vector<int> dist(V+1, INF); dist[from] = 0;

    while (!pq.empty()) {
        auto [sd, s] = pq.top(); pq.pop();

        if (dist[s] < sd) continue;

        for (auto [t, td] : G[s]) {
            if (sd+td < dist[t]) {
                dist[t] = sd+td;
                pq.push({sd+td, t});
            }
        }
    }

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M; cin >> V >> M;
    G.resize(V+1);
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        if (G[a].find(b) == G[a].end()) G[a][b] = G[b][a] = c;
        else G[a][b] = G[b][a] = min(G[a][b], c);
    }
    int J, S; cin >> J >> S;

    vector<int> d1 = dijkstra(J), d2 = dijkstra(S);
    int t = INF;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= V; i++) {
        if (i == J || i == S) continue;
        if (d1[i] == INF || d2[i] == INF) continue;

        int d = d1[i]+d2[i];
        if (d < t) {
            ans.clear();
            t = d;
        }
        if (d == t && d1[i] <= d2[i]) ans.push_back({d1[i], i});
    }
    sort(ans.begin(), ans.end());

    cout << (ans.size() ? ans[0].second : -1) << '\n';

    return 0;
}
