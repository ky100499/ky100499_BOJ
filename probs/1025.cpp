#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

int A[9][9];

bool isSquare(int n)
{
    int m = sqrt(n);
    return m*m == n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            A[i][j] = c-'0';
        }
    }

    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (isSquare(A[i][j])) ans = max(ans, A[i][j]);

            for (int dx = -i; dx < N-i; dx++) {
                for (int dy = -j; dy < M-j; dy++) {
                    if (dx == 0 && dy == 0) continue;

                    queue<tuple<int, int, int>> q; q.emplace(i, j, A[i][j]);
                    while (!q.empty()) {
                        auto [x, y, n] = q.front(); q.pop();

                        if (isSquare(n)) ans = max(ans, n);

                        int nx = x+dx, ny = y+dy;
                        if (in(nx, 0, N) && in(ny, 0, M))
                            q.emplace(nx, ny, 10*n + A[nx][ny]);
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
