#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<vector<int>> dist(N+1, vector<int>(N+1, INF));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    while (M--) {
        int u, v, b; cin >> u >> v >> b;
        dist[u][v] = 0;
        dist[v][u] = !b;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                if (dist[j][k] > dist[j][i]+dist[i][k])
                    dist[j][k] = dist[j][i]+dist[i][k];

    int K; cin >> K;
    while (K--) {
        int s, e; cin >> s >> e;
        cout << dist[s][e] << '\n';
    }

    return 0;
}
