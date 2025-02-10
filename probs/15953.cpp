#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 5000,
          INF = 1e9;

map<int, int> G[MAX+1];
int A[MAX/2], B[MAX/2],
    dist[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, J, K; cin >> N >> M >> J >> K;
    for (int i = 0; i < K; i++) cin >> A[i];
    for (int i = 0; i < K; i++) cin >> B[i];
    while (M--) {
        int x, y, z; cin >> x >> y >> z;
        if (G[x].find(y) == G[x].end()) G[x][y] = G[y][x] = z;
        else G[x][y] = G[y][x] = min(G[x][y], z);
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, J);
    fill(dist+1, dist+N+1, INF); dist[J] = 0;
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;

        for (auto [t, w] : G[s]) {
            if (dist[t] > d+w) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    char ans; int ansd = INF;
    for (int i = 0; i < K; i++) {
        if (dist[A[i]] < ansd) {
            ansd = dist[A[i]];
            ans = 'A';
        }
    }
    for (int i = 0; i < K; i++) {
        if (dist[B[i]] < ansd) {
            ansd = dist[B[i]];
            ans = 'B';
        }
    }
    if (ansd == INF) cout << "-1\n";
    else cout << ans << '\n' << ansd << '\n';

    return 0;
}
