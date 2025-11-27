#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+1,
          INF = 1e9;

int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    fill(dp, dp+K+1, INF); dp[0] = 0;
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        for (int k = K-c; k >= 0; k--)
            dp[k+c] = min(dp[k+c], dp[k]+1);
    }

    cout << (dp[K] == INF ? -1 : dp[K]) << '\n';

    return 0;
}
