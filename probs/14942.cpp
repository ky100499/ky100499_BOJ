#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5,
          MAXD = 17;

int E[MAX+1], V[MAX+1] = {};
pi dist[MAX+1][MAXD];       // { node, distance }
map<int, int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> E[i];
    for (int i = 1; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }

    for (int i = 0; i < MAXD; i++) dist[1][i] = {1, 0};

    queue<int> q; q.push(1); V[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, w] : G[u]) {
            if (V[v]) continue;

            dist[v][0] = {u, w};
            for (int i = 1; i < MAXD; i++) {
                int tmp = dist[v][i-1].first;
                dist[v][i] = {
                    dist[tmp][i-1].first,
                    dist[v][i-1].second + dist[tmp][i-1].second
                };
            }

            V[v] = 1;
            q.push(v);
        }
    }

    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int j = MAXD-1; j >= 0; j--) {
            if (dist[pos][j].second <= E[i]) {
                E[i] -= dist[pos][j].second;
                pos = dist[pos][j].first;
            }
        }
        cout << pos << '\n';
    }

    return 0;
}
