#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9,
          MAX = 1001;

map<int, int> G[MAX];
int dist[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, X; cin >> N >> M >> X;
    while (M--) {
        int a, b, t; cin >> a >> b >> t;
        if (G[a].find(b) == G[a].end()) G[a][b] = G[b][a] = t;
        else G[a][b] = G[b][a] = min(t, G[a][b]);
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, X);
    fill(dist+1, dist+N+1, INF); dist[X] = 0;
    int ans = 0;
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;
        ans = max(ans, d);

        for (auto [t, w] : G[s]) {
            if (dist[t] > d+w) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    cout << ans * 2 << '\n';

    return 0;
}
