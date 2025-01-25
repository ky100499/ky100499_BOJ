#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX = 1e4;

int P[MAX+1],
    F[MAX+1],
    id = 0;
vi G[MAX+1];
vvi SCC;
stack<int> S;

int dfs(int u)
{
    int res = P[u] = ++id;
    S.push(u);
    for (int v : G[u]) {
        if (P[v] == 0) res = min(res, dfs(v));
        else if (!F[v]) res = min(res, P[v]);
    }

    if (res == P[u]) {
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

    return res;
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

    for (int i = 1; i <= V; i++)
        if (!P[i]) dfs(i);
    sort(SCC.begin(), SCC.end(), [](vi a, vi b) { return a[0] < b[0]; });

    cout << SCC.size() << '\n';
    for (auto scc : SCC) {
        for (int s : scc) cout << s << ' ';
        cout << "-1\n";
    }

    return 0;
}
