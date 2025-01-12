#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

int n[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[2][MAX+1] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 1; i <= MAX; i++) {
        for (int j = 0; j < 10; j++) {
            int c = n[j];
            if (i-c >= 0) {
                if (dp[0][i-c].size() >= dp[0][i].size()) {
                    dp[0][i] = max(to_string(j)+dp[0][i-c], dp[0][i-c]+to_string(j));
                }
                else if (dp[0][i-c].size()+1 == dp[0][i].size()) {
                    dp[0][i] = max(max(to_string(j)+dp[0][i-c], dp[0][i-c]+to_string(j)), dp[0][i]);
                }
            }
        }
    }

    for (int i = 1; i <= MAX; i++) {
        dp[1][i] = string(100, '9');
        for (int j = 0; j < 10; j++) {
            int c = n[j];
            if (i-c >= 0) {
                if (!dp[1][i].size() || dp[1][i-c].size()+1 < dp[1][i].size()) {
                    if (j) dp[1][i] = min(to_string(j)+dp[1][i-c], dp[1][i-c]+to_string(j));
                    else if (dp[1][i-c].size()) dp[1][i] = dp[1][i-c]+to_string(j);
                }
                else if (dp[1][i-c].size()+1 == dp[1][i].size()) {
                    string tmp;
                    if (j) tmp = min(to_string(j)+dp[1][i-c], dp[1][i-c]+to_string(j));
                    else tmp = dp[1][i-c]+to_string(j);

                    dp[1][i] = min(tmp, dp[1][i]);
                }
            }
        }
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << dp[1][N] << ' ' << dp[0][N] << '\n';
    }

    return 0;
}
