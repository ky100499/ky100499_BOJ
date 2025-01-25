#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX = 1e4;

int P[MAX+1],
    F[MAX+1];
vi G[MAX+1];
vvi SCC;
stack<int> S;

int dfs(int u)
{
    S.push(u);
    P[u] = u;
    for (int v : G[u]) {
        if (P[v] == 0) P[u] = min(P[u], dfs(v));
        else if (!F[v]) P[u] = min(P[u], P[v]);
    }

    if (P[u] == u) {
        vi ans;
        while (1) {
            int v = S.top(); S.pop();
            ans.push_back(v);
            F[v] = 1;
            if (u == v) break;
        }
        sort(ans.begin(), ans.end());
        SCC.push_back(ans);
    }

    return P[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int V, E; cin >> V >> E;
    while (E--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    memset(P, 0, sizeof P);
    memset(F, 0, sizeof F);

    for (int i = 0; i <= V; i++)
        if (!F[i]) dfs(i);

    cout << SCC.size() << '\n';
    for (auto scc : SCC) {
        for (int s : scc) cout << s << ' ';
        cout << "-1\n";
    }

    return 0;
}
