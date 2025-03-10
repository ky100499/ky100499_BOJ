#include <bits/stdc++.h>

using namespace std;

int A[40][40], S[10][10], tmp[10][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K, ans = 0; cin >> N >> M >> K;
    memset(A, 0, sizeof A);
    while (K--) {
        int R, C; cin >> R >> C;
        memset(S, 0, sizeof S);
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> S[i][j];

        int f = 0;
        for (int t = 0; t < 4 && !f; t++) {
            for (int r = 0; r <= N-R && !f; r++) {
                for (int c = 0; c <= M-C && !f; c++) {
                    int fit = 1;
                    for (int i = 0; i < R && fit; i++)
                        for (int j = 0; j < C && fit; j++)
                            if (A[r+i][c+j] && S[i][j]) fit = 0;

                    if (fit) {
                        f = 1;
                        for (int i = 0; i < R; i++) {
                            for (int j = 0; j < C; j++) {
                                A[r+i][c+j] += S[i][j];
                                ans += S[i][j];
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < C; i++)
                for (int j = 0; j < R; j++)
                    tmp[i][j] = S[R-j-1][i];
            memcpy(S, tmp, sizeof S);
            swap(R, C);
        }
    }

    cout << ans << '\n';

    return 0;
}
