#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using qi = tuple<int, int, int, int>;

const int INF = 1e9;

char B[20][20];
int dp[10][1<<10],
    adj[10][10],
    dist_cleaner[10],
    dist[20][20],
    len, MAX,
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, };

int solve(int i, int v)
{
    if (v == MAX) dp[i][v] = 0;
    if (dp[i][v] == INF) {
        for (int j = 0; j < len; j++) {
            if ((v & (1<<j)) == 0) {
                dp[i][v] = min(dp[i][v], solve(j, v|(1<<j)) + adj[i][j]);
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
        pi s;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> B[i][j];
                if (B[i][j] == '*') dusts.emplace_back(i, j);
                else if (B[i][j] == 'o') {
                    s = {i, j};
                    B[i][j] = '.';
                }
            }
        }

        fill(&dp[0][0], &dp[10][0], INF);
        fill(&adj[0][0], &adj[10][0], INF);
        fill(&dist_cleaner[0], &dist_cleaner[10], INF);

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

        fill(&dist[0][0], &dist[20][0], INF); dist[s.first][s.second] = 0;
        queue<ti> q; q.emplace(0, s.first, s.second);
        while (!q.empty()) {
            auto [d, u, v] = q.front(); q.pop();

            if (d > dist[u][v]) continue;

            if (B[u][v] == '*') {
                for (int j = 0; j < len; j++) {
                    if (dusts[j].first == u && dusts[j].second == v) {
                        dist_cleaner[j] = d;
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

        bool cleanable = 1;
        for (int i = 0; i < len; i++)
            if (dist_cleaner[i] == INF)
                cleanable = 0;

        if (cleanable) {
            int ans = INF;
            for (int i = 0; i < len; i++) {
                ans = min(ans, dist_cleaner[i] + solve(i, 1<<i));
            }
            cout << ans << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
