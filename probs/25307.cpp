#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 2000,
          INF = 1e9;

int A[MAX][MAX], B[MAX][MAX], D[MAX][MAX],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K, x, y; cin >> N >> M >> K;
    queue<ti> P, Q;
    fill(&B[0][0], &B[N][0], INF);
    fill(&D[0][0], &D[N][0], INF);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            if (A[i][j] == 3) P.emplace(i, j, 0), B[i][j] = 0;
            if (A[i][j] == 4) Q.emplace(i, j, 0), A[i][j] = D[i][j] = 0;
        }
    }
    while (!P.empty()) {
        auto [x, y, d] = P.front(); P.pop();

        if (B[x][y] < d || d == K) continue;

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M) && d+1 < B[nx][ny]) {
                P.emplace(nx, ny, d+1);
                B[nx][ny] = d+1;
            }
        }
    }

    int ans = -1;
    while (!Q.empty()) {
        auto [x, y, d] = Q.front(); Q.pop();

        if (D[x][y] < d) continue;
        if (A[x][y] == 2) {
            ans = d;
            break;
        }

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 0, N) && in(ny, 0, M) && A[nx][ny] != 1 && B[nx][ny] > K && d+1 < D[nx][ny]) {
                Q.emplace(nx, ny, d+1);
                D[nx][ny] = d+1;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
