#include <bits/stdc++.h>

using namespace std;

const int MAX = 2500,
          INF = 1e9;

int P[MAX][MAX], dp[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    int l = S.size();

    fill(&P[0][0], &P[l][0], 1);
    for (int i = 0; i < l; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (S[i] == S[j] && P[j+1][i-1]) P[j][i] = 1;
            else P[j][i] = 0;
        }
    }

    fill(dp, dp+l, INF);
    for (int i = 0; i < l; i++) {
        if (P[0][i]) dp[i] = 1;
        else {
            for (int j = 1; j <= i; j++) {
                if (P[j][i]) dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
    }
    cout << dp[l-1] << '\n';

    return 0;
}
