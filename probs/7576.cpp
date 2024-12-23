#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 1000;

int B[MAX][MAX],
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, cnt = 0; cin >> M >> N;
    queue<pi> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];

            if (B[i][j] == 0) cnt++;
            else if (B[i][j] == 1) q.emplace(i, j);
        }
    }

    if (cnt) {
        int t = 0;
        for (; cnt && q.size(); t++) {
            for (int i = q.size(); i; i--) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : mv) {
                    int nx = x+dx, ny = y+dy;
                    if (in(nx, 0, N) && in(ny, 0, M) && B[nx][ny] == 0) {
                        B[nx][ny] = 1;
                        cnt--;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
        cout << (cnt ? -1 : t) << '\n';
    }
    else cout << "0\n";

    return 0;
}
