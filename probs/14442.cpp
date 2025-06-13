#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using qi = tuple<int, int, int, int>;

const int MAX = 1000,
          INF = 1e9;

string A[MAX];
int D[MAX][MAX][11],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    fill(&D[0][0][0], &D[N][0][0], INF);

    queue<qi> q; q.emplace(0, 0, 1, 0); D[0][0][0] = 1;
    int ans = -1;
    while (!q.empty()) {
        auto [x, y, d, k] = q.front(); q.pop();

        if (D[x][y][k] < d) continue;
        if (x == N-1 && y == M-1) {
            ans = d;
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (!in(nx, 0, N) || !in(ny, 0, M)) continue;

            if (A[nx][ny] == '0' && D[nx][ny][k] > d+1) {
                D[nx][ny][k] = d+1;
                q.emplace(nx, ny, d+1, k);
            }
            if (A[nx][ny] == '1' && k < K && D[nx][ny][k+1] > d+1) {
                D[nx][ny][k+1] = d+1;
                q.emplace(nx, ny, d+1, k+1);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
