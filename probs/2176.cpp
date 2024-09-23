#include <bits/stdc++.h>

#define INF 2e9

using namespace std;

typedef pair<int, int> pi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<map<int, int>> G(N+1);
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, 2});
    vector<int> dist(N+1, INF); dist[2] = 0;
    vector<int> dp(N+1); dp[2] = 1;
    while (!pq.empty()) {
        auto [sd, s] = pq.top(); pq.pop();

        if (dist[s] < sd) continue;

        for (auto [t, d] : G[s]) {
            if (sd+d < dist[t]) {
                dist[t] = sd+d;
                pq.push({sd+d, t});
            }
            if (sd > dist[t]) dp[s] += dp[t];
        }
    }
    cout << dp[1] << '\n';

    return 0;
}
