#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;

int D[MAX], dp[MAX][502];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> D[i];
    memset(dp, -1, sizeof dp); dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        for (int j = 0; j <= M; j++) {
            if (dp[i][j] == -1) continue;

            dp[i+1][j+1] = dp[i][j]+D[i];
            if (i+j <= N) dp[i+j][0] = max(dp[i+j][0], dp[i][j]);
        }
    }

    cout << dp[N][0] << '\n';

    return 0;
}
