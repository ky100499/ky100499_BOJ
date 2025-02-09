#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int A[MAX][2], dp[MAX][16][16];

int solve(int i, int w, int b)
{
    if (w == 0 && b == 0) return 0;
    if (i < 0 || w < 0 || b < 0) return -1e9;

    return dp[i][w][b] = dp[i][w][b] ? dp[i][w][b] : max(
        solve(i-1, w, b),
        max(
            solve(i-1, w-1, b) + A[i][0],
            solve(i-1, w, b-1) + A[i][1]
        )
    );
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N = 0;
    while (1) {
        cin >> A[N][0] >> A[N][1];
        if (cin.eof()) break;
        N++;
    }

    cout << solve(N-1, 15, 15) << '\n';

    return 0;
}
