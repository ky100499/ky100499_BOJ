#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5,
          MOD = 1e9+7;

int G[8][8] = {
    { 0, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 1 },
    { 0, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 1, 0 },
},
    dp[MAX+1][8] = { {1,} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int D; cin >> D;
    for (int i = 1; i <= D; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                if (G[j][k]) dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    cout << dp[D][0] << '\n';

    return 0;
}
