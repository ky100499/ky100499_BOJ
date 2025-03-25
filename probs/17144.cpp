#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

int A[50][50], tmp[50][50],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int R, C, T, cl = -1; cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if (cl == -1 && A[i][j] == -1) cl = i;
        }
    }

    while (T--) {
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (A[i][j] > 0) {
                    int d = A[i][j]/5;
                    for (auto [di, dj] : mv) {
                        int ni = i+di, nj = j+dj;
                        if (in(ni, 0, R) && in(nj, 0, C) && A[ni][nj] != -1) {
                            tmp[ni][nj] += d;
                            A[i][j] -= d;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (tmp[i][j] > 0) {
                    A[i][j] += tmp[i][j];
                }
            }
        }

        for (int r = cl-1; r; r--) A[r][0] = A[r-1][0];
        for (int c = 0; c < C-1; c++) A[0][c] = A[0][c+1];
        for (int r = 0; r < cl; r++) A[r][C-1] = A[r+1][C-1];
        for (int c = C-1; c > 1; c--) A[cl][c] = A[cl][c-1];
        A[cl][1] = 0;

        for (int r = cl+2; r < R-1; r++) A[r][0] = A[r+1][0];
        for (int c = 0; c < C-1; c++) A[R-1][c] = A[R-1][c+1];
        for (int r = R-1; r > cl+1; r--) A[r][C-1] = A[r-1][C-1];
        for (int c = C-1; c > 1; c--) A[cl+1][c] = A[cl+1][c-1];
        A[cl+1][1] = 0;
    }

    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (A[i][j] > 0) ans += A[i][j];
    cout << ans << '\n';

    return 0;
}
