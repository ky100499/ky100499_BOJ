#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

int N, A[1<<6][1<<6], tmp[1<<6][1<<6], V[1<<6][1<<6],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int dfs(int x, int y)
{
    if (V[x][y]) return 0;
    V[x][y] = 1;

    int ret = 1;

    for (auto [dx, dy] : mv) {
        int nx = x+dx, ny = y+dy;
        if (in(nx, 0, 1<<N) && in(ny, 0, 1<<N) && A[nx][ny] && !V[nx][ny])
            ret += dfs(nx, ny);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int Q; cin >> N >> Q;
    for (int i = 0; i < 1<<N; i++)
        for (int j = 0; j < 1<<N; j++)
            cin >> A[i][j];

    while (Q--) {
        int L; cin >> L;

        for (int r = 0; r < 1<<N; r += 1<<L) {
            for (int c = 0; c < 1<<N; c += 1<<L) {
                for (int i = 0; i < 1<<L; i++) {
                    for (int j = 0; j < 1<<L; j++) {
                        tmp[r+j][c+(1<<L)-1-i] = A[r+i][c+j];
                    }
                }
            }
        }
        memcpy(A, tmp, sizeof A);

        memset(tmp, 0, sizeof tmp);
        memset(V, 0, sizeof V);
        for (int i = 0; i < 1<<N; i++) {
            for (int j = 0; j < 1<<N; j++) {
                if (!A[i][j] && !V[i][j]) {
                    queue<pi> q; q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();

                        if (V[x][y]) continue;
                        V[x][y] = 1;

                        for (auto [dx, dy] : mv) {
                            int nx = x+dx, ny = y+dy;
                            if (in(nx, 0, 1<<N) && in(ny, 0, 1<<N)) {
                                if (!A[nx][ny]) q.emplace(nx, ny);
                                else tmp[nx][ny]++;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 1<<N; i++) {
            tmp[0][i]++;
            tmp[i][0]++;
            tmp[(1<<N)-1][i]++;
            tmp[i][(1<<N)-1]++;
        }

        for (int i = 0; i < 1<<N; i++) {
            for (int j = 0; j < 1<<N; j++) {
                if (tmp[i][j] >= 2 && A[i][j]) A[i][j]--;
            }
        }
    }

    memset(V, 0, sizeof V);
    int s = 0, ans = 0;
    for (int i = 0; i < 1<<N; i++) {
        for (int j = 0; j < 1<<N; j++) {
            s += A[i][j];
            if (A[i][j] && !V[i][j]) ans = max(ans, dfs(i, j));
        }
    }

    cout << s << '\n' << ans << '\n';

    return 0;
}
