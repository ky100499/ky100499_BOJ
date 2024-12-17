#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1000,
          INF = 1e9;

map<int, int> G[MAX+1];
int dist[3][MAX+1];

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
    int S[3]; for (int i = 0; i < 3; i++) cin >> S[i];

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;
        dist[i][S[i]] = 0;

        priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, S[i]);
        while (!pq.empty()) {
            auto [d, s] = pq.top(); pq.pop();

            if (dist[i][s] < d) continue;

            for (auto [t, w] : G[s]) {
                if (dist[i][t] > d+w) {
                    dist[i][t] = d+w;
                    pq.emplace(d+w, t);
                }
            }
        }
    }

    int pt, min_d = INF;
    for (int i = 1; i <= N; i++) {
        int d = 0;
        for (int j = 0; j < 3; j++) d += dist[j][i];

        if (d < min_d) {
            min_d = d;
            pt = i;
        }
    }

    vector<pi> ans;
    for (int i = 0; i < 3; i++) {
        int s = pt;
        while (dist[i][s]) {
            for (auto [t, w] : G[s]) {
                if (dist[i][t]+w == dist[i][s]) {
                    ans.emplace_back(s, t);
                    s = t;
                    break;
                }
            }
        }
    }

    cout << min_d << ' ' << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';

    return 0;
}
