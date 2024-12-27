#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using qi = tuple<int, int, int, int>;

const int INF = 1e9;

char B[20][20];
int dp[11][1<<11],
    adj[11][11],
    dist[20][20],
    len, MAX,
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, };

int solve(int i, int v)
{
    if (v == MAX) dp[i][v] = 0;
    if (dp[i][v] == INF) {
        for (int j = 0; j < len; j++) {
            if ((v & (1<<j)) == 0) {
                int s = solve(j, v|(1<<j));
                if (s == -1 || adj[i][j] == INF) dp[i][v] = -1;
                else dp[i][v] = min(dp[i][v], s + adj[i][j]);
            }
        }
    }
    return dp[i][v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        int W, H; cin >> W >> H;
        if (W == 0) break;

        vector<pi> dusts;
        int origin;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> B[i][j];
                if (B[i][j] == '*') dusts.emplace_back(i, j);
                else if (B[i][j] == 'o') {
                    origin = dusts.size();
                    dusts.emplace_back(i, j);
                    B[i][j] = '*';
                }
            }
        }

        fill(&dp[0][0], &dp[11][0], INF);
        fill(&adj[0][0], &adj[11][0], INF);

        len = dusts.size(); MAX = (1<<len) - 1;
        for (int i = 0; i < len; i++) {
            auto [x, y] = dusts[i];
            fill(&dist[0][0], &dist[20][0], INF); dist[x][y] = 0;
            queue<ti> q; q.emplace(0, x, y);
            while (!q.empty()) {
                auto [d, u, v] = q.front(); q.pop();

                if (d > dist[u][v]) continue;

                if (B[u][v] == '*') {
                    for (int j = 0; j < len; j++) {
                        if (dusts[j].first == u && dusts[j].second == v) {
                            adj[i][j] = d;
                            break;
                        }
                    }
                }

                for (auto [du, dv] : mv) {
                    int nu = u+du, nv = v+dv;

                    if (in(nu, 0, H) && in(nv, 0, W) && B[nu][nv] != 'x' && dist[nu][nv] > d+1) {
                        dist[nu][nv] = d+1;
                        q.emplace(d+1, nu, nv);
                    }
                }
            }
        }

        int ans = INF;
        ans = min(ans, solve(origin, 1<<origin));
        cout << ans << '\n';
    }

    return 0;
}
