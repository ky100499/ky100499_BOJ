#include <bits/stdc++.h>

using namespace std;

const int MAX = 50,
          INF = 1e9;

int dp[MAX][MAX];

int dfs(int s, int e, string S)
{
    if (e <= s) return 0;

    if (dp[s][e] == INF) {
        dp[s][e] = min(
            dfs(s+1, e-1, S) + (S[s] != S[e]),
            min(dfs(s, e-1, S), dfs(s+1, e, S)) + 1
        );
    }

    return dp[s][e];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    int len = S.size();

    fill(&dp[0][0], &dp[len][0], INF);
    int ans = dfs(0, len-1, S);
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (S[i] != S[j]) {
                swap(S[i], S[j]);
                fill(&dp[0][0], &dp[len][0], INF);
                ans = min(ans, dfs(0, len-1, S)+1);
                swap(S[i], S[j]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
