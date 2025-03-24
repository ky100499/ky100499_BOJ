#include <bits/stdc++.h>

using namespace std;

int S[201][201];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    int ans = -1e9;
    memset(S, 0, sizeof S);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int x; cin >> x;
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + x;

            for (int r = 0; r < i; r++) {
                for (int c = 0; c < j; c++) {
                    ans = max(ans, S[i][j] - S[r][j] - S[i][c] + S[r][c]);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
