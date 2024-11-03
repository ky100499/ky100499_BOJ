#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(N, vector<int>(4, INF));
    dp[0][0] = A[0]; dp[0][1] = 1;
    for (int i = 1; i < N; i++) {
        if (dp[i-1][0] <= A[i]) dp[i][0] = A[i];
        for (int j = 1; j < 4; j++) {
            dp[i][j] = dp[i-1][j-1];
            if (dp[i-1][j] <= A[i]) dp[i][j] = min(dp[i][j], A[i]);
        }
    }

    int x = min_element(dp[N-1].begin(), dp[N-1].end()) - dp[N-1].begin();
    if (dp[N-1][x] == INF) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n' << x << '\n';
        for (int i = N-1; i >= 0 && x > 0; i--) {
            if (i == 0 || dp[i-1][x] > A[i] || dp[i-1][x-1] < A[i]) {
                cout << i+1 << ' ' << dp[i][x--] << '\n';
            }
        }
    }

    return 0;
}
