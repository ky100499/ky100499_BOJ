#include <bits/stdc++.h>

using namespace std;

const int MAX = 50,
          INF = 1e9;

int dp[MAX][MAX], len;

int solve(string S)
{
    fill(&dp[0][0], &dp[len][0], INF);
    for (int i = 0; i < len; i++) dp[i][i] = 0;
    for (int i = 1; i < len; i++) dp[i-1][i] = S[i-1] != S[i];

    for (int l = 0; l < len-1; l++) {
        for (int s = 0; s+l < len; s++) {
            if (s > 0) dp[s-1][s+l] = min(dp[s-1][s+l], dp[s][s+l]+1);
            if (s+l+1 < len) dp[s][s+l+1] = min(dp[s][s+l+1], dp[s][s+l]+1);
            if (s > 0 && s+l+1 < len) dp[s-1][s+l+1] = min(dp[s-1][s+l+1], dp[s][s+l]+(S[s-1] != S[s+l+1]));
        }
    }

    return dp[0][len-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    len = S.size();

    int ans = solve(S);
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (S[i] != S[j]) {
                swap(S[i], S[j]);
                ans = min(ans, solve(S)+1);
                swap(S[i], S[j]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
