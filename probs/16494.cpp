#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

int A[21],
    S[21],
    dp[21][21][21];

int solve(int l, int h, int k)
{
    if (k == 0) return 0;
    if (h < l || h-l+1 < k) return -INF;
    if (h == l) return A[l];

    if (dp[l][h][k] == -INF) {
        dp[l][h][k] = S[h] - S[l-1];
        for (int m = l; m <= h; m++) {
            for (int i = 0; i <= k; i++) {
                dp[l][h][k] = max(
                    dp[l][h][k],
                    solve(l, m-1, i) + solve(m+1, h, k-i)
                );
            }
        }
    }

    return dp[l][h][k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }

    fill(&dp[1][0][0], &dp[N+1][0][0], -INF);
    cout << solve(1, N, M) << '\n';

    return 0;
}
