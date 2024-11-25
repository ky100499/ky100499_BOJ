#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

bool reachable(int s, int e, vector<map<int, int>> G)
{
    queue<int> q({s});
    int V[50] = {}; V[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, _] : G[u]) {
            if (!V[v]) {
                V[v] = 1;
                q.push(v);
            }
        }
    }
    return V[e];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, A, B, M; cin >> N >> A >> B >> M;
    vector<map<int, int>> G(N);
    int money[50];
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (G[u].find(v) == G[u].end()) G[u][v] = w;
        else G[u][v] = min(G[u][v], w);
    }
    for (int i = 0; i < N; i++) cin >> money[i];

    if (!reachable(A, B, G)) {
        cout << "gg\n";
        return 0;
    }

    vector<ll> dist(N, INF); dist[A] = -money[A];
    for (int i = 0; i < N; i++) {
        for (int u = 0; u < N; u++) {
            for (auto [v, w] : G[u]) {
                if (dist[v] > dist[u] + w - money[v]) {
                    dist[v] = dist[u] + w - money[v];
                    if (i == N-1 && reachable(A, v, G) && reachable(v, B, G)) {
                        cout << "Gee\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << -dist[B] << '\n';

    return 0;
}
