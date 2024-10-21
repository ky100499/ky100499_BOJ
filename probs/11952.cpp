#include <bits/stdc++.h>

#define MAX 100000

using namespace std;
using ll = long long;
using pi = pair<ll, int>;
using ti = tuple<int, int, int>;

ll INF = 1e12;

int fee[MAX+1];
vector<int> G[MAX+1];
ll cost[MAX+1] = { 0, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K, S; cin >> N >> M >> K >> S;
    int p, q; cin >> p >> q;

    for (int i = 1; i <= N; i++)
        fee[i] = p;

    vector<int> z(K);
    while (K--) {
        int c; cin >> c;
        z[K] = c;
    }

    while (M--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int c : z) {
        queue<pi> qu({{0, c}});
        vector<int> V(N+1); V[c] = 1;
        while (!qu.empty()) {
            auto [m, c] = qu.front(); qu.pop();

            if (m == 0) fee[c] = -1;
            else fee[c] = q;

            if (m == S) continue;

            for (int n : G[c]) {
                if (!V[n] && fee[n] != -1) {
                    V[n] = 1;
                    qu.push({m+1, n});
                }
            }
        }
    }
    fee[1] = fee[N] = 0;

    for (int i = 2; i <= N; i++) cost[i] = INF;

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, 1});
    while (!pq.empty()) {
        auto [c, s] = pq.top(); pq.pop();

        if (s == N) {
            cout << c << '\n';
            break;
        }

        if (cost[s] < c) continue;

        for (int t : G[s]) {
            ll nc = c+fee[t];
            if (fee[t] != -1 && nc < cost[t]) {
                cost[t] = nc;
                pq.push({nc, t});
            }
        }
    }

    return 0;
}
