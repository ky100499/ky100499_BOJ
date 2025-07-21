#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

int N, M, D, ans = 0,
    A[15][15], rm[15][15], V[15][15],
    C[15],
    mv[][2] = { {0,-1}, {-1,0}, {0,1} };

int solve()
{
    int ret = 0;

    memset(rm, -1, sizeof rm);
    for (int R = N-1; R >= 0; R--) {
        for (int i = 0; i < M; i++) {
            if (C[i]) {
                memset(V, 0, sizeof V); V[R][i] = 1;
                queue<ti> q; q.emplace(R, i, 1);
                while (!q.empty()) {
                    auto [x, y, d] = q.front(); q.pop();

                    if (A[x][y] && rm[x][y] <= R) {
                        if (rm[x][y] == -1) ret++;
                        rm[x][y] = R;
                        break;
                    }

                    if (d == D) continue;
                    for (auto [dx, dy] : mv) {
                        int nx = x+dx, ny = y+dy;
                        if (in(nx, 0, N) && in(ny, 0, M) && !V[nx][ny]) {
                            V[nx][ny] = 1;
                            q.emplace(nx, ny, d+1);
                        }
                    }
                }
            }
        }
    }

    return ret;
}

void comb(int i, int n)
{
    if (n == 3) {
        ans = max(ans, solve());
        return;
    }

    for (int j = i; j < M; j++) {
        C[j] = 1;
        comb(j+1, n+1);
        C[j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    comb(0, 0);
    cout << ans << '\n';

    return 0;
}
