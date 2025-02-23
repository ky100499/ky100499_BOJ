#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int dp[51][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, H; cin >> N >> M >> H;
    memset(dp, 0, sizeof dp); dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= H; j++)
            dp[i][j] = dp[i-1][j];
        do {
            int h; cin >> h;
            for (int j = h; j <= H; j++)
                dp[i][j] = (dp[i][j] + dp[i-1][j-h]) % MOD;
        } while (cin.peek() != EOF && cin.peek() != '\n');
    }
    cout << dp[N][H] << '\n';

    return 0;
}
