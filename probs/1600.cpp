#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 200, INF = 1e9;

int A[MAX][MAX], V[MAX][MAX][31],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} },
    mv2[8][2] = { {1,2}, {2,1}, {1,-2}, {-2,1}, {-1,2}, {2,-1}, {-1,-2}, {-2,-1} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int K, W, H; cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];

    fill(&V[0][0][0], &V[H][0][0], INF); V[0][0][0] = 0;
    queue<ti> q; q.emplace(0, 0, 0);
    int ans = INF;
    while (!q.empty()) {
        auto [x, y, k] = q.front(); q.pop();

        if (x == H-1 && y == W-1) {
            ans = V[x][y][k];
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, H) && in(ny, 0, W) && !A[nx][ny] && V[nx][ny][k] > V[x][y][k]+1) {
                V[nx][ny][k] = V[x][y][k]+1;
                q.emplace(nx, ny, k);
            }
        }

        if (k == K) continue;
        for (auto [dx, dy] : mv2) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, H) && in(ny, 0, W) && !A[nx][ny] && V[nx][ny][k+1] > V[x][y][k]+1) {
                V[nx][ny][k+1] = V[x][y][k]+1;
                q.emplace(nx, ny, k+1);
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}
