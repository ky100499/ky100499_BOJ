#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 100;

int A[MAX][MAX], V[MAX][MAX],
    mv[][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    int ans = 1;
    for (int h = 1; h < 100; h++) {
        memset(V, 0, sizeof V);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] > h && !V[i][j]) {
                    cnt++;
                    queue<pi> q; q.emplace(i, j);
                    V[i][j] = 1;
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();

                        for (auto [dx, dy] : mv) {
                            int nx = x+dx, ny = y+dy;
                            if (in(nx, 0, N) && in(ny, 0, N) && A[nx][ny] > h && !V[nx][ny]) {
                                q.emplace(nx, ny);
                                V[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        if (cnt == 0) break;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}
