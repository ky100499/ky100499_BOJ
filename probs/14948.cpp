#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using qi = tuple<int, int, int, int>;

int A[100][100],
    D[100][100][2],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    memset(D, 0x3f, sizeof D); D[0][0][0] = A[0][0];
    priority_queue<qi, vector<qi>, greater<qi>> pq; pq.emplace(A[0][0], 0, 0, 0);
    int ans;
    while (!pq.empty()) {
        auto [d, x, y, j] = pq.top(); pq.pop();

        if (D[x][y][j] < d) continue;
        if (x == N-1 && y == M-1) {
            ans = d;
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M)) {
                int nd = max(d, A[nx][ny]);
                if (nd < D[nx][ny][j]) {
                    D[nx][ny][j] = nd;
                    pq.emplace(nd, nx, ny, j);
                }
            }

            nx += dx, ny += dy;
            if (!j && in(nx, 0, N) && in(ny, 0, M)) {
                int nd = max(d, A[nx][ny]);
                if (nd < D[nx][ny][1]) {
                    D[nx][ny][1] = nd;
                    pq.emplace(nd, nx, ny, 1);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
