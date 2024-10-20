#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int deg[10001] = { 0, };
vector<pi> G[10001], G_rev[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        deg[v]++;
        G[u].push_back({v, w});
        G_rev[v].push_back({u, w});
    }
    int S, T; cin >> S >> T;

    int dist[10001] = { 0, };
    queue<int> q({S});
    while (!q.empty()) {
        int s = q.front(); q.pop();

        for (auto [t, td] : G[s]) {
            dist[t] = max(dist[t], dist[s]+td);
            if (--deg[t] == 0) q.push(t);
        }
    }

    int V[10001] = { 0, };
    function<int(int)> dfs = [&](int s) -> int {
            if (V[s]) return 0;
            V[s] = 1;

            int ret = 0;
            for (auto [t, d] : G_rev[s]) {
                if (dist[t] == dist[s]-d) {
                    ret += 1 + dfs(t);
                }
            }

            return ret;
        };
    cout << dist[T] << '\n' << dfs(T) << '\n';

    return 0;
}
