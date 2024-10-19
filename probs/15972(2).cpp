#include <bits/stdc++.h>

using namespace std;
using ti = tuple<int, int, int>;

int W[1002][1002];
vector<ti> G[1002][1002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, L; cin >> N >> M >> L;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            W[i][j] = L;

    priority_queue<ti, vector<ti>, greater<ti>> pq;

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int ipt; cin >> ipt;

            if (ipt != -1) {
                if (i == 0) pq.push({0, i, j});
                if (i == N) pq.push({0, N+1, j});

                G[i][j].push_back({i+1, j, ipt});
                G[i+1][j].push_back({i, j, ipt});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            int ipt; cin >> ipt;

            if (ipt != -1) {
                if (j == 0) pq.push({0, i, j});
                if (j == M) pq.push({0, i, M+1});

                G[i][j].push_back({i, j+1, ipt});
                G[i][j+1].push_back({i, j, ipt});
            }
        }
    }

    while (!pq.empty()) {
        auto [w, x, y] = pq.top(); pq.pop();

        if (w > W[x][y]) continue;

        for (auto [nx, ny, h] : G[x][y]) {
            int nw = max(w, h);
            if (W[nx][ny] > nw) {
                W[nx][ny] = nw;
                pq.push({nw, nx, ny});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            ans += W[i][j];
    cout << ans << '\n';

    return 0;
}
