#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int INF = 1e9;

int N, M;
vector<map<int, int>> G;

pair<int, vector<int>> dijkstra(int b1, int b2)
{
    vector<int> dist(N+1, INF); dist[1] = 0;
    vector<int> prev(N+1, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, 1});
    while (!pq.empty()) {
        auto [sd, s] = pq.top(); pq.pop();

        if (s == N) break;

        if (sd > dist[s]) continue;

        for (auto [t, d] : G[s]) {
            if ((s==b1 && t==b2) || (s==b2 && t==b1)) continue;

            if (dist[t] > sd+d) {
                dist[t] = sd+d;
                pq.push({sd+d, t});
                prev[t] = s;
            }
        }
    }

    return {dist[N], prev};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    G.resize(N+1);
    while (M--) {
        int x, y, z; cin >> x >> y >> z;
        G[x][y] = G[y][x] = z;
    }

    auto [dist, prev] = dijkstra(-1, -1);
    int cur = N;
    while (prev[cur] != -1) {
        int nd = dijkstra(cur, prev[cur]).first;
        dist = max(dist, nd);
        cur = prev[cur];
    }

    cout << dist << '\n';

    return 0;
}
