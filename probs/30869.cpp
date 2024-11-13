#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

vector<ti> G[501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K; cin >> N >> M >> K;
    while (M--) {
        int s, e, t, g; cin >> s >> e >> t >> g;
        G[s].emplace_back(e, t, g);
    }

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, 0, 1);
    vector<vector<int>> dist(N+1, vector<int>(K+1, INF)); dist[1][0] = 0;
    int ans = -1;
    while (!pq.empty()) {
        auto [d, k, s] = pq.top(); pq.pop();

        if (dist[s][k] < d) continue;

        if (s == N) {
            ans = d;
            break;
        }

        for (auto [e, t, g] : G[s]) {
            if (d % g) {
                if (k < K && dist[e][k+1] > d+t) {
                    dist[e][k+1] = d+t;
                    pq.emplace(d+t, k+1, e);
                }
            }

            int nd = d;
            if (d % g) nd = (d / g + 1) * g;
            if (dist[e][k] > nd+t) {
                dist[e][k] = nd+t;
                pq.emplace(nd+t, k, e);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
