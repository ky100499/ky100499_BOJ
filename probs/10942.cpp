#include <bits/stdc++.h>

using namespace std;

const int MAX = 2001;

int A[MAX],
    dp[MAX][MAX];

int solve(int s, int e)
{
    if (e <= s) return 1;
    if (dp[s][e] != -1) return dp[s][e];
    return dp[s][e] = A[s] == A[e] && solve(s+1, e-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    int M; cin >> M;

    memset(dp, -1, sizeof dp);
    while (M--) {
        int s, e; cin >> s >> e;
        cout << solve(s, e) << '\n';
    }

    return 0;
}
