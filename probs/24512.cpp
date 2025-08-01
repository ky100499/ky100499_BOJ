#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000000,
          INF = 1e9;

int N;
int G[10][10];
int dist[10][1<<10];

int TSP(int i, int v)
{
    if (dist[i][v] != INF*2) return dist[i][v];

    if (v == (1<<(N+1))-2) {
        return dist[i][v] = G[i][1];
    }

    int ret = INF;
    for (int j = 1; j <= N; j++) {
        if (!(v & (1<<j)) && G[i][j] != INF) {
            ret = min(ret, max(G[i][j], TSP(j, v|(1<<j))));
        }
    }
    return dist[i][v] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M; cin >> N >> M;
    fill(&G[1][0], &G[N+1][0], INF);
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G[u][v] = w;
    }

    fill(&dist[1][0], &dist[N+1][0], INF*2);
    int ans = TSP(1, 1<<1);

    if (ans > MAX) cout << "-1\n";
    else {
        cout << ans << '\n';
        int i = 1, v = 1<<1;
        cout << "1 ";
        while (v != (1<<(N+1))-2) {
            for (int j = 1; j <= N; j++) {
                if (!(v & (1<<j)) && max(G[i][j], dist[j][v|(1<<j)]) == dist[i][v]) {
                    cout << j << ' ';
                    i = j;
                    v |= 1<<j;
                    break;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
