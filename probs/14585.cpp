#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int dp[301];
pi C[301];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    C[0] = {0,0};
    for (int i = 1; i <= N; i++) cin >> C[i].first >> C[i].second;
    sort(C, C+N+1);

    memset(dp, 0, sizeof dp);
    for (int i = N; i > 0; i--) {
        auto [x, y] = C[i];
        if (x+y > M) continue;

        for (int j = i-1; j >= 0; j--) {
            auto [u, v] = C[j];
            if (u <= x && v <= y) dp[j] = max(dp[j], dp[i]+M-x-y);
        }
    }

    cout << dp[0] << '\n';

    return 0;
}
