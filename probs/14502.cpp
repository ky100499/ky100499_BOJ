#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

int A[8][8], N, M, n = 3, ans = 0,
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int bfs()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 2) {
                queue<pi> q; q.emplace(i, j);
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();

                    for (auto [dx, dy] : mv) {
                        int nx = x+dx, ny = y+dy;
                        if (in(nx, 0, N) && in(ny, 0, M) && A[nx][ny] != 1 && A[nx][ny] != 2 && A[nx][ny] != n) {
                            A[nx][ny] = n;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ret += A[i][j] != 1 && A[i][j] != 2 && A[i][j] != n;
    n++;

    return ret;
}

void bt(int r, int c, int cnt)
{
    if (cnt == 3) {
        ans = max(ans, bfs());
        return;
    }

    if (c == M) {
        r++;
        c = 0;
    }
    if (r == N) return;

    if (A[r][c] != 1 && A[r][c] != 2) {
        A[r][c] = 1;
        bt(r, c+1, cnt+1);
        A[r][c] = 0;
    }
    bt(r, c+1, cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    bt(0, 0, 0);
    cout << ans << '\n';

    return 0;
}
