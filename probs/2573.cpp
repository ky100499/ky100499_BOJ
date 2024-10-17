#include <bits/stdc++.h>

using namespace std;

int mv[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
int B[300][300] = {{0,},};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    int t = 0;
    while (1) {
        vector<vector<int>> V(N, vector<int>(M));
        vector<tuple<int, int, int>> rm;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!B[i][j] || V[i][j]) continue;
                cnt++;

                queue<pair<int, int>> q({{i, j}});
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();

                    if (V[x][y]) continue;
                    V[x][y] = 1;

                    int c = 0;
                    for (auto m : mv) {
                        int nx = x+m[0], ny = y+m[1];
                        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                            if (B[nx][ny] && !V[nx][ny]) q.push({nx, ny});
                            else if (!B[nx][ny]) c++;
                        }
                    }
                    rm.push_back({x, y, min(c, B[x][y])});
                }
            }
        }

        if (cnt > 1) {
            cout << t << '\n';
            break;
        }
        else if (rm.empty()) {
            cout << "0\n";
            break;
        }

        for (auto [x, y, c] : rm) B[x][y] -= c;
        t++;
    }

    return 0;
}
