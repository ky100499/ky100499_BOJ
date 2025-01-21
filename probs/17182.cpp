#include <bits/stdc++.h>

using namespace std;

const int MAX = 10,
          INF = 1e9;

int N, K, adj[MAX][MAX], dp[MAX][1<<MAX];

int solve(int s, int v)
{
    if (dp[s][v] == INF) {
        if (v == (1<<N)-1) dp[s][v] = 0;
        else {
            for (int t = 0; t < N; t++)
                if (!(v&(1<<t)))
                    dp[s][v] = min(dp[s][v], adj[s][t]+solve(t, v|(1<<t)));
        }
    }
    return dp[s][v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> adj[i][j];

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

    fill(&dp[0][0], &dp[MAX][0], INF);
    cout << solve(K, 1<<K) << '\n';

    return 0;
}
