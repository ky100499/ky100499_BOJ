#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

const int MAX = 100;

char B[MAX][MAX];
int dp[80][MAX][MAX],
    mv[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];
    string S; cin >> S;

    memset(dp, 0, sizeof dp);

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (B[j][k] == S[i]) {
                    if (i == 0) {
                        dp[i][j][k] = 1;
                        continue;
                    }

                    for (auto [dj, dk] : mv) {
                        for (int l = 1; l <= K; l++) {
                            int nj = j+l*dj, nk = k+l*dk;
                            if (in(nj, 0, N) && in(nk, 0, M))
                                dp[i][j][k] += dp[i-1][nj][nk];
                            else break;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < N; j++)
        for (int k = 0; k < M; k++)
            ans += dp[S.size()-1][j][k];
    cout << ans << '\n';

    return 0;
}
