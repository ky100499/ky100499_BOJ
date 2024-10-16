#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int mv[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0},
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<vector<int>> B(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    int t = 0, c;
    while (1) {
        queue<pi> q({{0, 0}});
        vector<vector<int>> V(N, vector<int>(M));
        vector<pi> cheese;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (V[x][y]) continue;
            V[x][y] = 1;

            if (B[x][y]) {
                cheese.push_back({x, y});
                continue;
            }

            for (auto m : mv) {
                int nx = x+m[0], ny = y+m[1];
                if (0 <= nx && nx < N && 0 <= ny && ny < M && !V[nx][ny]) q.push({nx, ny});
            }
        }

        if (cheese.empty()) break;
        c = cheese.size();
        t++;

        for (auto [x, y] : cheese) B[x][y] -= 1;
    }

    cout << t << '\n' << c << '\n';

    return 0;
}
