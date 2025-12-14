#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000,
          MOD = 10007;

string S;
int dp[MAX][MAX];

int solve(int s, int e)
{
    if (s == e) return 1;
    if (s > e) return 0;

    int &a = dp[s][e];
    if (a == -1) {
        a = solve(s,e-1) + solve(s+1,e);
        if (S[s] == S[e]) a++;
        else a += MOD - solve(s+1, e-1);
        a %= MOD;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> S;
    memset(dp, -1, sizeof dp);
    cout << solve(0, S.size()-1) << '\n';

    return 0;
}
