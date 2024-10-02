#include <bits/stdc++.h>

#define INF (ll)1e12

using namespace std;
using ll = long long;
using ti = tuple<ll, int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<int> price(N+1);
    for (int i = 1; i <= N; i++) cin >> price[i];
    vector<map<int, int>> G(N+1);
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.push({0, 1, price[1]});
    vector<vector<ll>> cost(N+1, vector<ll>(2501, INF)); cost[1][price[1]] = 0;
    while (!pq.empty()) {
        auto [c, n, p] = pq.top(); pq.pop();
        p = min(p, price[n]);

        if (n == N) {
            cout << c << '\n';
            break;
        }

        if (c > cost[n][p]) continue;

        for (auto [t, d] : G[n]) {
            ll nc = c+p*d;
            if (nc < cost[t][p]) {
                cost[t][p] = nc;
                pq.push({nc, t, p});
            }
        }
    }

    return 0;
}
