#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int dp[2][3][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    for (int i = 0; i < 3; i++) {
        cin >> dp[0][i][0];
        dp[0][i][1] = dp[0][i][0];
    }
    for (int i = 1; i < N; i++) {
        int ipt[3];
        for (int j = 0; j < 3; j++) cin >> ipt[j];

        dp[i%2][0][0] = ipt[0] + max({
            dp[(i+1)%2][0][0],
            dp[(i+1)%2][1][0],
        });
        dp[i%2][1][0] = ipt[1] + max({
            dp[(i+1)%2][0][0],
            dp[(i+1)%2][1][0],
            dp[(i+1)%2][2][0],
        });
        dp[i%2][2][0] = ipt[2] + max({
            dp[(i+1)%2][1][0],
            dp[(i+1)%2][2][0],
        });

        dp[i%2][0][1] = ipt[0] + min({
            dp[(i+1)%2][0][1],
            dp[(i+1)%2][1][1],
        });
        dp[i%2][1][1] = ipt[1] + min({
            dp[(i+1)%2][0][1],
            dp[(i+1)%2][1][1],
            dp[(i+1)%2][2][1],
        });
        dp[i%2][2][1] = ipt[2] + min({
            dp[(i+1)%2][1][1],
            dp[(i+1)%2][2][1],
        });
    }

    cout << max({
        dp[(N+1)%2][0][0],
        dp[(N+1)%2][1][0],
        dp[(N+1)%2][2][0],
    }) << ' ' << min({
        dp[(N+1)%2][0][1],
        dp[(N+1)%2][1][1],
        dp[(N+1)%2][2][1],
    }) << '\n';

    return 0;
}
