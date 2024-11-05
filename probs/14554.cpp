#include <bits/stdc++.h>

#define MAX 100001

using namespace std;
using ll = long long;
using pi = pair<ll, int>;

const ll INF = 1e18;
const int MOD = 1e9+9;

vector<pair<int, int>> G[MAX];
int cnt[MAX];
ll dist[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, S, E; cin >> N >> M >> S >> E;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, S});
    for (int i = 1; i <= N; i++) {
        dist[i] = i == S ? 0 : INF;
        cnt[i] = i == S ? 1 : 0;
    }
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;

        if (s == E) break;

        for (auto [t, w] : G[s]) {
            if (dist[t] == d+w) {
                cnt[t] = (cnt[t]+cnt[s]) % MOD;
            }
            else if (dist[t] > d+w) {
                cnt[t] = cnt[s];
                dist[t] = d+w;
                pq.push({d+w, t});
            }
        }
    }
    cout << cnt[E] << '\n';

    return 0;
}
