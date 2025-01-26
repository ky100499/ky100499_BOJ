#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int MAX = 2e5;

int V1[MAX+1],
    V2[MAX+1];
vi G1[MAX+1],
   G2[MAX+1];

void dfs(int u, vi G[], int V[])
{
    for (int v : G[u]) {
        if (!V[v]) {
            V[v] = 1;
            dfs(v, G, V);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (M--) {
        int u, v; cin >> u >> v;
        G1[u].push_back(v);
        G2[v].push_back(u);
    }

    memset(V1, 0, sizeof V1); V1[1] = 1;
    memset(V2, 0, sizeof V2); V2[1] = 1;

    dfs(1, G1, V1);
    dfs(1, G2, V2);

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        if (!V1[i] || !V2[i]) {
            ans = 0;
            break;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
