#include <bits/stdc++.h>

#define INF (int)2e9

using namespace std;
using ti = tuple<int, int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    int S, D; cin >> S >> D;
    vector<map<int, int>> G(N+1);
    while (M--) {
        int a, b, w; cin >> a >> b >> w;
        G[a][b] = G[b][a] = w;
    }
    vector<int> P(K+1);
    for (int i = 0; i < K; i++) cin >> P[i];

    vector<int> ans(K+1, INF);
    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.push({0, S, 0});
    vector<vector<int>> dist(N+1, vector<int>(N+1, INF));
    for (int i = 0; i <= N; i++) dist[S][i] = 0;
    while (!pq.empty()) {
        auto [sd, s, c] = pq.top(); pq.pop();

        if (s == D) {
            int nd = sd;
            for (int i = 0; i <= K; i++) {
                ans[i] = min(ans[i], nd);
                nd += P[i]*c;
            }
            continue;
        }

        if (sd > dist[s][c]) continue;

        for (auto [t, d] : G[s]) {
            int nd = sd+d;
            if (c < N && dist[t][c+1] > nd) {
                pq.push({nd, t, c+1});
                for (int i = c+1; i <= N; i++) {
                    if (dist[t][i] > nd) dist[t][i] = nd;
                    else break;
                }
            }
        }
    }

    for (int i = 0; i <= K; i++) cout << ans[i] << '\n';

    return 0;
}
