#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using vti = vector<ti>;
using vvti = vector<vti>;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int K, N, R; cin >> K >> N >> R;
    vvti G; G.resize(N+1);
    while (R--) {
        int s, d, l, t; cin >> s >> d >> l >> t;
        G[s].emplace_back(d, l, t);
    }

    priority_queue<ti, vti, greater<ti>> pq; pq.emplace(0, 0, 1);
    vector<vector<int>> dist(N+1, vector<int>(K+1, INF));
    fill(dist[1].begin(), dist[1].end(), 0);
    while (!pq.empty()) {
        auto [l, t, s] = pq.top(); pq.pop();

        if (dist[s][t] < l) continue;

        for (auto [d, dl, dt] : G[s]) {
            int nl = l+dl, nt = t+dt;
            if (nt <= K && dist[d][nt] > nl) {
                for (int i = nt; i <= K; i++) dist[d][i] = min(dist[d][i], nl);
                pq.emplace(nl, nt, d);
            }
        }
    }

    cout << (dist[N][K] == INF ? -1 : dist[N][K]) << '\n';

    return 0;
}
