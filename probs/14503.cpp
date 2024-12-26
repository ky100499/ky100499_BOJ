#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

int B[MAX][MAX],
    mv[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, r, c, d; cin >> N >> M >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    int cnt = 0;
    while (1) {
        if (B[r][c] == 0) {
            B[r][c] = 2;
            cnt++;
        }

        int dirty = 0;
        for (auto [dr, dc] : mv) {
            int nr = r+dr, nc = c+dc;
            dirty |= B[nr][nc] == 0;
        }

        if (dirty) {
            d = (d+3) % 4;
            int nr = r+mv[d][0], nc = c+mv[d][1];
            if (B[nr][nc] == 0) {
                r = nr;
                c = nc;
            }
        }
        else {
            int nr = r+mv[(d+2)%4][0], nc = c+mv[(d+2)%4][1];
            if (B[nr][nc] == 1) break;
            else {
                r = nr;
                c = nc;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
