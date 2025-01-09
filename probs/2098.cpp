#include <bits/stdc++.h>

using namespace std;

const int MAX = 16,
          INF = 1e9;

int N,
    dist[MAX][MAX],
    dp[MAX][1<<MAX];

int tsp(int i, int v)
{
    if (dp[i][v] == INF) {
        if (v == (1<<N)-1)
            dp[i][v] = dist[i][0] ? dist[i][0] : INF/10;
        else {
            for (int j = 0; j < N; j++)
                if (dist[i][j] && !(v&(1<<j)))
                    dp[i][v] = min(dp[i][v], dist[i][j]+tsp(j, v|(1<<j)));
        }
    }
    return dp[i][v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    fill(&dp[0][0], &dp[N][0], INF);
    cout << tsp(0, 1) << '\n';

    return 0;
}
