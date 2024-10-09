#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using pi = tuple<ull, int>;

ull INF = 1e18;
int MAX = 1e9;

int N, M, A, B; ull C;
vector<map<int, int>> G;

bool dijkstra(int M)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, A});
    vector<ull> dist(N+1, INF); dist[A] = 0;
    while (!pq.empty()) {
        auto [c, s] = pq.top(); pq.pop();

        if (s == B) return 1;

        if (dist[s] < c) continue;

        for (auto [t, tc] : G[s]) {
            if (tc > M) continue;

            ull nc = c+tc;
            if (nc <= C && dist[t] > nc) {
                dist[t] = nc;
                pq.push({nc, t});
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M >> A >> B >> C;
    G.resize(N+1);
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }

    int ans = MAX+1, l = 0, h = MAX;
    while (l <= h) {
        int m = (l+h)/2;

        if (!dijkstra(m)) {
            l = m+1;
        }
        else {
            h = m-1;
            ans = m;
        }
    }
    cout << (ans == MAX+1 ? -1 : ans) << '\n';

    return 0;
}
