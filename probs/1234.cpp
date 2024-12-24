#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[11][56][56][56];
int N, fact[11];

ll solve(int n, int r, int g, int b)
{
    if (n > N) return 1;

    if (dp[n][r][g][b] != -1) return dp[n][r][g][b];

    ll ret = 0;

    // 1개
    if (r >= n) ret += solve(n+1, r-n, g, b);
    if (g >= n) ret += solve(n+1, r, g-n, b);
    if (b >= n) ret += solve(n+1, r, g, b-n);

    // 2개
    if (n%2 == 0) {
        if (r >= n/2 && g >= n/2) ret += (fact[n] / fact[n/2] / fact[n/2]) * solve(n+1, r-n/2, g-n/2, b);
        if (g >= n/2 && b >= n/2) ret += (fact[n] / fact[n/2] / fact[n/2]) * solve(n+1, r, g-n/2, b-n/2);
        if (b >= n/2 && r >= n/2) ret += (fact[n] / fact[n/2] / fact[n/2]) * solve(n+1, r-n/2, g, b-n/2);
    }

    // 3개
    if (n%3 == 0) {
        if (r >= n/3 && g >= n/3 && b >= n/3) ret += (fact[n] / fact[n/3] / fact[n/3] / fact[n/3]) * solve(n+1, r-n/3, g-n/3, b-n/3);
    }

    return dp[n][r][g][b] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int R, G, B; cin >> N >> R >> G >> B;
    fill(&dp[0][0][0][0], &dp[11][0][0][0], -1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 11; i++) fact[i] = fact[i-1]*i;

    cout << solve(1, min(R, 55), min(G, 55), min(B, 55)) << '\n';

    return 0;
}
