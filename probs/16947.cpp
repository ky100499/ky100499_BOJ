#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 3001;

int V[MAX], L[MAX], D[MAX];
vector<int> G[MAX];

int dfs(int u, int p)
{
    if (V[u]) {
        L[u] = 1;
        return u;
    }

    V[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;

        int ret = dfs(v, u);
        if (ret == u) return 0;
        else if (ret) {
            L[u] = 1;
            return ret;
        }
    }
    V[u] = 0;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(V, 0, sizeof V);
    memset(L, 0, sizeof L);
    dfs(1, 0);

    memset(D, -1, sizeof D);
    for (int i = 1; i <= N; i++) {
        queue<pi> q; q.emplace(i, 0);
        memset(V, 0, sizeof V);
        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();

            if (V[u]) continue;
            V[u] = 1;

            if (L[u]) {
                D[i] = d;
                break;
            }

            if (D[u] != -1) {
                D[i] = min(D[i] == -1 ? 999999 : D[i], D[u]+d);
                continue;
            }

            for (int v : G[u]) {
                q.emplace(v, d+1);
            }
        }
        cout << D[i] << ' ';
    }
    cout << '\n';

    return 0;
}
