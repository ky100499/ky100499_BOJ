#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 8;

int N, M, A[MAX][MAX], V[MAX][MAX], ans = 1e9,
    mv[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} },
    dir[][4] = { {0,}, {0,1,0,0}, {0,1,0,1}, {1,1,0,0}, {1,1,0,1}, {1,1,1,1} },
    maxr[] = { 0, 4, 2, 4, 4, 1 };
vector<pi> CCTV;

void bt(int c)
{
    if (c == CCTV.size()) {
        int s = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!A[i][j] && !V[i][j]) s++;
        ans = min(ans, s);
        return;
    }

    auto [x, y] = CCTV[c];
    for (int r = 0; r < maxr[A[x][y]]; r++) {
        for (int d = 0; d < 4; d++) {
            if (dir[A[x][y]][(d+r)%4]) {
                int nx = x+mv[d][0], ny = y+mv[d][1];
                while (in(nx, 0, N) && in(ny, 0, M) && A[nx][ny] != 6) {
                    V[nx][ny]++;
                    nx += mv[d][0];
                    ny += mv[d][1];
                }
            }
        }

        bt(c+1);

        for (int d = 0; d < 4; d++) {
            if (dir[A[x][y]][(d+r)%4]) {
                int nx = x+mv[d][0], ny = y+mv[d][1];
                while (in(nx, 0, N) && in(ny, 0, M) && A[nx][ny] != 6) {
                    V[nx][ny]--;
                    nx += mv[d][0];
                    ny += mv[d][1];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            if (in(A[i][j], 1, 5)) CCTV.emplace_back(i, j);
            else if (A[i][j] == 5) CCTV.emplace(CCTV.begin(), i, j);
        }
    }

    memset(V, 0, sizeof V);
    bt(0);
    cout << ans << '\n';

    return 0;
}
