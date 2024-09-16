#include <iostream>

using namespace std;

int MOD = 1e9+7;

int dp[200000][5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < 5; i++) dp[0][i] = 1;

    for (int i = 1; i < N; i++) {
        long long s = 0; for (int j = 0; j < 5; j++) s += dp[i-1][j];

        dp[i][0] = (s - dp[i-1][0]) % MOD;
        dp[i][1] = (s - dp[i-1][1]-dp[i-1][2]) % MOD;
        dp[i][2] = (s - dp[i-1][1]-dp[i-1][2]-dp[i-1][3]) % MOD;
        dp[i][3] = (s - dp[i-1][2]-dp[i-1][3]-dp[i-1][4]) % MOD;
        dp[i][4] = (s - dp[i-1][3]-dp[i-1][4]) % MOD;
    }

    int ans = 0; for (int i = 0; i < 5; i++) ans = (ans + dp[N-1][i]) % MOD;
    cout << ans << '\n';

    return 0;
}
