#include <bits/stdc++.h>

using namespace std;

/*
** 0 1 2 3 4 5 6
** x o x x o o x
** x x o x o x o
** x x x o x o o
*/
int dp[31][7] = { {1, 0, 0, 0, 1, 0, 1}, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        dp[i][1] = dp[i-1][6];
        dp[i][2] = dp[i-1][5];
        dp[i][3] = dp[i-1][4];
        dp[i][4] = dp[i-1][3] + dp[i][0];
        dp[i][5] = dp[i-1][2];
        dp[i][6] = dp[i-1][1] + dp[i][0];

        dp[i+1][0] = dp[i][1] + dp[i][3] + dp[i-1][0];
    }

    cout << dp[N][0] << '\n';

    return 0;
}
