#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll X[2000], Y[2000], dp[2000][2000];

ll solve(int x, int y)
{
    if (dp[x][y] != -1) return dp[x][y];

    ll& ret = dp[x][y] = (X[x]-Y[y])*(X[x]-Y[y]);

    if (x == N-1 && y == N-1);
    else if (x == N-1) ret += solve(x, y+1);
    else if (y == N-1) ret += solve(x+1, y);
    else ret += min(
        solve(x+1, y+1),
        min(
            solve(x, y+1),
            solve(x+1, y)
        )
    );

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < N; i++) cin >> Y[i];

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';

    return 0;
}
