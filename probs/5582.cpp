#include <bits/stdc++.h>

using namespace std;

int dp[4001][4001] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string A, B; cin >> A >> B;
    int ans = 0;

    for (int i = 0; i < A.length(); i++) {
        for (int j = 0; j < B.length(); j++) {
            if (A[i] == B[j]) dp[i+1][j+1] = dp[i][j]+1;
            ans = max(ans, dp[i+1][j+1]);
        }
    }

    cout << ans << '\n';

    return 0;
}
