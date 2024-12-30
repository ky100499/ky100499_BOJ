#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using qi = tuple<int, int, int, int>;

const int INF = 1e9;

char B[50][50];
int dist[50][50][1<<6],
    mv[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    int sx, sy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
            if (B[i][j] == '0') {
                sx = i;
                sy = j;
                B[i][j] = '.';
            }
        }
    }

    fill(&dist[0][0][0], &dist[50][0][0], INF); dist[sx][sy][0] = 0;
    queue<qi> q; q.emplace(0, sx, sy, 0);
    int ans = -1;
    while (!q.empty()) {
        auto [d, x, y, k] = q.front(); q.pop();

        if (d > dist[x][y][k]) continue;
        if (B[x][y] == '1') {
            ans = d;
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M)) {
                if (
                    (
                        B[nx][ny] == '.' || B[nx][ny] == '1' ||
                        (in(B[nx][ny], 'A', 'G') && k & (1<<(B[nx][ny]-'A')))
                    ) && dist[nx][ny][k] > d+1
                ) {
                    dist[nx][ny][k] = d+1;
                    q.emplace(d+1, nx, ny, k);
                }
                else if (in(B[nx][ny], 'a', 'g')) {
                    int nk = k|(1<<(B[nx][ny]-'a'));
                    if (dist[nx][ny][nk] > d+1) {
                        dist[nx][ny][nk] = d+1;
                        q.emplace(d+1, nx, ny, nk);
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
