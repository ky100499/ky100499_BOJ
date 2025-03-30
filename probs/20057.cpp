#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

int A[500][500],
    mv[4][2] = { {0,-1}, {1,0}, {0,1}, {-1,0} },
    sand[4][5][5] = {
        {
            { 0, 0, 2, 0, 0 },
            { 0, 10, 7, 1, 0 },
            { 5, 0, 0, 0, 0 },
            { 0, 10, 7, 1, 0 },
            { 0, 0, 2, 0, 0 },
        },
        {
            { 0, 0, 0, 0, 0 },
            { 0, 1, 0, 1, 0 },
            { 2, 7, 0, 7, 2 },
            { 0, 10, 0, 10, 0 },
            { 0, 0, 5, 0, 0 },
        },
        {
            { 0, 0, 2, 0, 0 },
            { 0, 1, 7, 10, 0 },
            { 0, 0, 0, 0, 5 },
            { 0, 1, 7, 10, 0 },
            { 0, 0, 2, 0, 0 },
        },
        {
            { 0, 0, 5, 0, 0 },
            { 0, 10, 0, 10, 0 },
            { 2, 7, 0, 7, 2 },
            { 0, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0 },
        },
    };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int len = 1, x = N/2, y = N/2, ans = 0, d = 0;
    while (len++) {
        for (int i = 0; i < len/2; i++) {
            if (x == 0 && y == 0) break;

            x += mv[d][0]; y += mv[d][1];

            int s = A[x][y];
            if (!s) continue;

            for (int dx = -2; dx <= 2; dx++) {
                for (int dy = -2; dy <= 2; dy++) {
                    int nx = x+dx, ny = y+dy,
                        am = s * sand[d][2+dx][2+dy] / 100;
                    if (!am) continue;

                    A[x][y] -= am;
                    if (in(nx, 0, N) && in(ny, 0, N)) A[nx][ny] += am;
                    else ans += am;
                }
            }

            int nx = x+mv[d][0], ny = y+mv[d][1];
            if (in(nx, 0, N) && in(ny, 0, N))
                A[x+mv[d][0]][y+mv[d][1]] += A[x][y];
            else
                ans += A[x][y];
            A[x][y] = 0;
        }
        d++; d %= 4;

        if (x == 0 && y == 0) break;
    }

    cout << ans << '\n';

    return 0;
}
