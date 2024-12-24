#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

vector<int> G[MAX];
int cost[MAX][3],
    dp[MAX][3][10] = {},
    vst[MAX][3] = {},
    V, Q, K;

void solve(int u, int prev, int color)
{
    if (vst[u][color]) return;
    vst[u][color] = 1;

    dp[u][color][cost[u][color]%K] = 1;

    if (G[u].size() > 1 || u == 1) {
        for (int v : G[u]) {
            if (v == prev) continue;
            for (int i = 0; i < 3; i++) solve(v, u, i);

            int tmp[10] = {};
            for (int i = 0; i < K; i++) {
                if (!dp[u][color][i]) continue;

                for (int nc = 0; nc < 3; nc++) {
                    if ((color == 1 && nc == 1) || (color == 2 && nc != 1) || (color != 1 && nc == 2)) continue;
                    for (int j = 0; j < K; j++) {
                        tmp[(i+j)%K] += dp[u][color][i] * dp[v][nc][j];
                        tmp[(i+j)%K] %= Q;
                    }
                }
            }
            for (int i = 0; i < K; i++) dp[u][color][i] = tmp[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> V >> Q >> K;
    for (int i = 1; i < V; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= V; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];

    for (int i = 0; i < 3; i++) solve(1, 0, i);

    int ans = 0;
    for (int i = 0; i < 3; i++) ans += dp[1][i][0];
    cout << ans % Q << '\n';

    return 0;
}
