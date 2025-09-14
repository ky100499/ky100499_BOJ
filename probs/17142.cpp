#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 50,
          INF = 1e9;

int N, M, ans = INF,
    A[MAX][MAX],
    D[MAX][MAX],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
vector<pi> U;
deque<pi> V;

void bt(int i, int m)
{
    if (m == M) {
        queue<pi> q(V);
        memset(D, 0, sizeof D);
        fill(&D[0][0], &D[N][0], INF);
        for (auto [x, y] : V) D[x][y] = 0;
        int t = 0;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (A[x][y] == 0) t = max(t, D[x][y]);

            for (auto [dx, dy] : mv) {
                int nx = x+dx, ny = y+dy;
                if (in(nx, 0, N) && in(ny, 0, N) && A[nx][ny] != 1 && D[nx][ny] > D[x][y]+1) {
                    D[nx][ny] = D[x][y]+1;
                    q.emplace(nx, ny);
                }
            }
        }

        int f = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 0 && D[i][j] == INF) {
                    f = 0;
                    break;
                }
            }
        }

        if (f) ans = min(ans, t);

        return;
    }
    if (i == U.size()) return;

    bt(i+1, m);

    V.push_back(U[i]);
    bt(i+1, m+1);
    V.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] == 2) U.emplace_back(i, j);
        }
    }

    bt(0, 0);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}
