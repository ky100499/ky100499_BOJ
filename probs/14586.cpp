#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

int dp[301];
pi D[301];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> D[i].first >> D[i].second;
    D[0] = {0,0}; sort(D, D+N+1);

    memset(dp, 0x3f, sizeof dp); dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        auto [x, h] = D[i];
        ll l = x-h, r = x+h;
        for (int j = i+1; j <= N; j++) {
            auto [rx, rh] = D[j];
            if (rx > r) break;
            dp[j] = min(dp[i-1]+1, dp[j]);
            r = max(r, rx+rh);
        }
        for (int j = i-1; j >= 0; j--) {
            auto [lx, lh] = D[j];
            dp[i] = min(dp[i], dp[j]+1);
            if (lx < l) break;
            l = min(l, lx-lh);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
