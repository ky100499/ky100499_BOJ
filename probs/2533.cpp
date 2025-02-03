#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6,
          INF = 1e9;

int dp[MAX+1][2];
vector<int> G[MAX+1];

int solve(int u, int p, int e)
{
    if (dp[u][e] == INF) {
        dp[u][e] = e;
        for (int v : G[u]) {
            if (v == p) continue;
            dp[u][e] += min(
                e ? solve(v, u, 0) : INF,
                solve(v, u, 1)
            );
        }
    }

    return dp[u][e];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    fill(&dp[0][0], &dp[N+1][0], INF);
    while (--N) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    solve(1, 0, 0);
    solve(1, 0, 1);
    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
