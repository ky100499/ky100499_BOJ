#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 5000,
          INF = 1e9;

map<int, int> G[MAX+1];
int H[MAX+1],
    dist[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, J, K; cin >> N >> M >> J >> K;
    memset(H, -1, sizeof H);
    for (int i = 0; i < K*2; i++) {
        int x; cin >> x;
        H[x] = i >= K;
    }
    while (M--) {
        int x, y, z; cin >> x >> y >> z;
        if (G[x].find(y) == G[x].end()) G[x][y] = G[y][x] = z;
        else G[x][y] = G[y][x] = min(G[x][y], z);
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, J);
    fill(dist+1, dist+N+1, INF); dist[J] = 0;
    int flg = 0;
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;
        if (H[s] == 0) {
            cout << "A\n" << d << '\n';
            flg = 1;
            break;
        }
        else if (H[s] == 1) {
            while (!pq.empty()) {
                auto [w, x] = pq.top(); pq.pop();
                if (d < w) break;
                if (H[x] == 0) {
                    cout << "A\n" << d << '\n';
                    flg = 1;
                    break;
                }
            }
            if (!flg) cout << "B\n" << d << '\n';
            flg = 1;
            break;
        }

        for (auto [t, w] : G[s]) {
            if (dist[t] > d+w) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    if (!flg) cout << "-1\n";

    return 0;
}
