#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, int>;
using ti = tuple<int, int, int>;

const int MAX = 5e4;
const ll  INF = 1e18;

ll dist[MAX+1];
vector<ti> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, T; cin >> N >> M >> T;
    while (M--) {
        int u, v, t, s; cin >> u >> v >> t >> s;
        G[u].emplace_back(v, t, s);
        G[v].emplace_back(u, t, s);
    }

    int l = 0, h = 1e9, ans = -1;
    while (l <= h) {
        int m = (l+h)/2;

        fill(dist, dist+N+1, INF); dist[1] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, 1);
        while (!pq.empty()) {
            auto [ut, u] = pq.top(); pq.pop();

            if (ut > dist[u]) continue;
            if (u == N) break;

            for (auto [v, t, s] : G[u]) {
                ll nt = ut + t + max(0, s-m);
                if (dist[v] > nt && nt <= T) {
                    dist[v] = nt;
                    pq.emplace(nt, v);
                }
            }
        }

        if (dist[N] == INF) {
            l = m+1;
        }
        else {
            h = m-1;
            ans = m;
        }
    }

    cout << ans << '\n';

    return 0;
}
