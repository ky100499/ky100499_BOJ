#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

int B[4][4][8] = {},
    tmp[4][4][8],
    smell[4][4] = {},
    V[4][4],
    mv[8][2] = {
        {0,-1},
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
    },
    ord[4] = { 2, 0, 6, 4 },
    dir[3], _dir[3], _max;
pi shark;

void bt(int x, int y, int n, int v)
{
    if (n == 3) {
        if (v > _max) {
            _max = v;
            memcpy(dir, _dir, sizeof dir);
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x+mv[ord[i]][0], ny = y+mv[ord[i]][1], nv = v;
        if (in(nx, 0, 4) && in(ny, 0, 4)) {
            _dir[n] = ord[i];
            if (!V[nx][ny]) {
                for (int j = 0; j < 8; j++)
                    nv += tmp[nx][ny][j];
            }
            V[nx][ny]++;
            bt(nx, ny, n+1, nv);
            V[nx][ny]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M, S; cin >> M >> S;
    while (M--) {
        int x, y, d; cin >> x >> y >> d;
        B[x-1][y-1][d-1]++;
    }
    cin >> shark.first >> shark.second;
    shark.first--; shark.second--;

    while (S--) {
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 8; k++) {
                    if (!B[i][j][k]) continue;

                    bool moved = 0;
                    for (int nk = k; nk-k < 56; nk += 7) {
                        int ni = i+mv[nk%8][0], nj = j+mv[nk%8][1];
                        if (in(ni, 0, 4) && in(nj, 0, 4) && !smell[ni][nj] && (ni != shark.first || nj != shark.second)) {
                            tmp[ni][nj][nk%8] += B[i][j][k];
                            moved = 1;
                            break;
                        }
                    }
                    if (!moved) tmp[i][j][k] += B[i][j][k];
                }
            }
        }

        memset(V, 0, sizeof V); _max = -1;
        bt(shark.first, shark.second, 0, 0);
        for (int i = 0; i < 3; i++) {
            shark.first += mv[dir[i]][0];
            shark.second += mv[dir[i]][1];
            int kill = 0;
            for (int j = 0; j < 8; j++) {
                kill += tmp[shark.first][shark.second][j];
                tmp[shark.first][shark.second][j] = 0;
            }
            if (kill) smell[shark.first][shark.second] = 3;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (smell[i][j]) smell[i][j]--;
                for (int k = 0; k < 8; k++)
                    tmp[i][j][k] += B[i][j][k];
            }
        }
        memcpy(B, tmp, sizeof B);
    }

    int ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 8; k++)
                ans += B[i][j][k];
    cout << ans << '\n';

    return 0;
}
