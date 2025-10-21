#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ti = tuple<int, int, int>;

const int MAX = 2e5+1;
const ll  INF = 1e18;

ll dp[MAX];
ti P[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K, H; cin >> N >> K >> H;
    for (int i = 0; i < K; i++) {
        int u, v, w; cin >> u >> v >> w;
        P[i] = { u, v, w };
    }

    fill(dp+1, dp+N, INF); dp[N] = 0;
    for (int i = K-1; i >= 0; i--) {
        auto [u, v, w] = P[i];
        ll du = dp[u], dv = dp[v];
        dp[u] = min(du+w, dv);
        dp[v] = min(dv+w, du);
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++)
        if (dp[i] != INF) ans = max(ans, dp[i]);

    cout << ans + (H-1) * dp[N] << '\n';

    return 0;
}
