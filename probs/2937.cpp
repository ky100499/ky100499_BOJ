#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

int A[MAX][MAX],
    S[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    memset(A, 0, sizeof A);
    memset(S, 0, sizeof S);
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        A[x][y] = 1;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            S[i][j] = A[i][j] + S[i-1][j] + S[i][j-1] - S[i-1][j-1];

    int ans = 1e9;
    for (int w = 1; w <= M; w++) {
        if (M % w) continue;

        int h = M/w;

        for (int i = 0; i+h <= N; i++)
            for (int j = 0; j+w <= N; j++)
                ans = min(ans, M - (S[i+h][j+w] - S[i][j+w] - S[i+h][j] + S[i][j]));
    }

    cout << ans << '\n';

    return 0;
}
