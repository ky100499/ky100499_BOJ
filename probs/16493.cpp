#include <bits/stdc++.h>

using namespace std;

const int MAX = 200;

int dp[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    memset(dp, 0, sizeof dp);

    while (M--) {
        int d, p; cin >> d >> p;
        for (int i = N; i >= d; i--) dp[i] = max(dp[i], dp[i-d]+p);
    }

    cout << dp[N] << '\n';

    return 0;
}
