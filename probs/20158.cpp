#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = tuple<int, int, int, int, int>;

const int INF = 1e9;

int X[100][100],
    T[100][100][4][20],
    mv[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> X[i][j];
            if (X[i][j] == 0) X[i][j] = INF;
        }
    }

    memset(T, 0x3f, sizeof T);
    for (int i = 0; i < 4; i++) T[0][0][i][1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q; q.emplace(0,0,0,-1,1);
    while (!q.empty()) {
        auto [t, x, y, d, s] = q.top(); q.pop();

        if (x == N-1 && y == N-1) {
            cout << t << '\n';
            return 0;
        }
        if (d != -1 && T[x][y][d][s] < t) continue;

        for (int nd = 0; nd < 4; nd++) {
            if (d == nd) {
                int nx = x+mv[d][0]*s, ny = y+mv[d][1]*s, g = 1;
                if (!in(nx, 0, N) || !in(ny, 0, N) || t+1 >= X[nx][ny] || t+1 >= T[nx][ny][d][s+1]) continue;

                int xx = x, yy = y;
                for (int i = 1; i < s; i++) {
                    xx += mv[d][0]; yy += mv[d][1];
                    if (t >= X[xx][yy]) g = 0;
                }

                if (g) {
                    T[nx][ny][d][s+1] = t+1;
                    q.emplace(t+1, nx, ny, d, s+1);
                }
            }
            else {
                int nx = x+mv[nd][0], ny = y+mv[nd][1];
                if (in(nx, 0, N) && in(ny, 0, N) && t+1 < X[nx][ny] && t+1 < T[nx][ny][nd][1]) {
                    T[nx][ny][nd][1] = t+1;
                    q.emplace(t+1, nx, ny, nd, 2);
                }
            }
        }
    }

    cout << "Fired\n";

    return 0;
}
