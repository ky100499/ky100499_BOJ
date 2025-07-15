#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 100;

int A[MAX][MAX], V[MAX][MAX],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int n = 1, ans = 1e9;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == 1) {
                queue<pi> q; q.emplace(i, j); A[i][j] = ++n;
                queue<ti> qq;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();

                    for (auto [dx, dy] : mv) {
                        int nx = x+dx, ny = y+dy;
                        if (!(in(nx, 0, N) && in(ny, 0, N))) continue;

                        if (A[nx][ny] == 1) {
                            A[nx][ny] = n;
                            q.emplace(nx, ny);
                        }
                        else if (A[nx][ny] == 0) qq.emplace(nx, ny, 1);
                    }
                }

                memset(V, 0, sizeof V);
                while (!qq.empty()) {
                    auto [x, y, c] = qq.front(); qq.pop();

                    if (c >= ans) break;
                    if (V[x][y]) continue;
                    V[x][y] = 1;

                    for (auto [dx, dy] : mv) {
                        int nx = x+dx, ny = y+dy;
                        if (!(in(nx, 0, N) && in(ny, 0, N))) continue;

                        if (A[nx][ny] == 1) ans = min(ans, c);
                        else if (A[nx][ny] == 0 && !V[nx][ny]) qq.emplace(nx, ny, c+1);
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
