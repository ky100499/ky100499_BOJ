#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int A[MAX][MAX], S = 0, P[5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            S += A[i][j];
        }
    }

    int ans = 1e9;
    for (int x = 0; x < N-2; x++) {
        for (int y = 1; y < N-1; y++) {
            for (int d1 = 1; d1 <= y; d1++) {
                for (int d2 = 1; y+d2 < N && x+d1+d2 < N; d2++) {
                    memset(P, 0, sizeof P); P[4] = S;

                    // 1
                    for (int r = 0; r < x+d1; r++)
                        for (int c = 0; c <= min(y, y-(r-x+1)); c++)
                            P[0] += A[r][c];
                    P[4] -= P[0];
                    // 2
                    for (int r = 0; r <= x+d2; r++)
                        for (int c = max(y, y+(r-x))+1; c < N; c++)
                            P[1] += A[r][c];
                    P[4] -= P[1];
                    // 3
                    for (int r = x+d1; r < N; r++)
                        for (int c = 0; c < min(y-d1+d2, y-d1+(r-x-d1)); c++)
                            P[2] += A[r][c];
                    P[4] -= P[2];
                    // 4
                    for (int r = x+d2+1; r < N; r++)
                        for (int c = max(y-d1+d2, y+d2-(r-x-d2)+1); c < N; c++)
                            P[3] += A[r][c];
                    P[4] -= P[3];

                    ans = min(ans, *max_element(P, P+5)-*min_element(P, P+5));
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
