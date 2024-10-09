#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using pdi = pair<double, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, W; cin >> N >> W;
    double M; cin >> M;
    vector<pii> pts(N+1);
    vector<vector<double>> len(N+1, vector<double>(N+1));
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
        for (int j = 1; j < i; j++) {
            double l = sqrt(pow(x-pts[j].first, 2) + pow(y-pts[j].second, 2));
            len[i][j] = len[j][i] = l;
        }
    }
    while (W--) {
        int u, v; cin >> u >> v;
        len[u][v] = len[v][u] = 0;
    }

    priority_queue<pdi, vector<pdi>, greater<pdi>> pq; pq.push({0, 1});
    vector<double> dist(N+1, 1e9); dist[1] = 0;
    while (!pq.empty()) {
        auto [sd, s] = pq.top(); pq.pop();

        if (s == N) {
            cout << ((int)(sd*1000)) << '\n';
            break;
        }

        if (sd > dist[s]) continue;

        for (int i = 1; i <= N; i++) {
            if (i == s || len[s][i] > M) continue;
            if (dist[i] > sd+len[s][i]) {
                dist[i] = sd+len[s][i];
                pq.push({sd+len[s][i], i});
            }
        }
    }

    return 0;
}
