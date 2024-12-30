#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dp[3][2][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    fill(&dp[0][0][0], &dp[3][0][0], INF);

    for (int i = 0; i < 3; i++)
        cin >> dp[i][0][i];

    for (int i = 1; i <= N; i++) {
        int r, g, b; cin >> r >> g >> b;
        if (cin.eof()) r = g = b = 0;
        for (int j = 0; j < 3; j++) {
            dp[j][i%2][0] = min(dp[j][(i+1)%2][1], dp[j][(i+1)%2][2]) + r;
            dp[j][i%2][1] = min(dp[j][(i+1)%2][2], dp[j][(i+1)%2][0]) + g;
            dp[j][i%2][2] = min(dp[j][(i+1)%2][0], dp[j][(i+1)%2][1]) + b;
        }
    }

    int ans = INF;
    for (int i = 0; i < 3; i++)
        ans = min(ans, dp[i][N%2][i]);
    cout << ans << '\n';

    return 0;
}
