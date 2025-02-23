#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, int>;

const int MAX = 1e5;
const ll  INF = 1e18;

map<int, int> G[MAX+1];
int rm[MAX+1];
ll  dist[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, C; cin >> N >> M >> C;
    ll D = 0;
    while (M--) {
        int a, b, d; cin >> a >> b >> d;
        D += (G[a][b] = G[b][a] = d);
    }

    fill(dist+1, dist+N+1, INF); dist[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (d > dist[s]) continue;

        for (auto [t, w] : G[s]) {
            if (dist[t] > d+w) {
                dist[t] = d+w;
                pq.emplace(d+w, t);
            }
        }
    }

    vector<pi> A(N);
    for (int i = 1; i <= N; i++)
        A[i-1] = {dist[i], i};
    sort(A.begin(), A.end());

    memset(rm, 0, sizeof rm);
    ll ans = INF;
    for (auto [d, u] : A) {
        rm[u] = 1;
        for (auto [v, w] : G[u]) {
            if (rm[v]) D -= w;
        }

        ans = min(ans, C*d + D);
    }

    cout << ans << '\n';

    return 0;
}
