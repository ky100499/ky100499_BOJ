#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using qi = tuple<int, int, int, int>;

const int MAX = 100,
          INF = 1e9;

int B[MAX][MAX][MAX],
    mv[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M, N, H, cnt = 0; cin >> M >> N >> H;
    queue<qi> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> B[i][j][k];
                if (B[i][j][k] == 0) cnt++;
                else if (B[i][j][k] == 1) q.emplace(0, i, j, k);
            }
        }
    }

    while (!q.empty()) {
        auto [t, x, y, z] = q.front(); q.pop();

        if (cnt == 0) {
            cout << t << '\n';
            break;
        }

        for (auto [dx, dy, dz] : mv) {
            int nx = x+dx, ny = y+dy, nz = z+dz;
            if (in(nx, 0, H) && in(ny, 0, N) && in(nz, 0, M) && B[nx][ny][nz] == 0) {
                B[nx][ny][nz] = 1;
                cnt--;
                q.emplace(t+1, nx, ny, nz);
            }
        }

        if (cnt == 0) {
            cout << t+1 << '\n';
            break;
        }
    }

    if (cnt) cout << -1 << '\n';

    return 0;
}
