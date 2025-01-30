#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

int N,
    id = 0,
    P[MAX],
    F[MAX],
    C[MAX],
    ans = 0;
string G[MAX];
stack<int> S;

int dfs(int u)
{
    int p = P[u] = ++id;
    S.push(u);

    for (int v = 0; v < N; v++) {
        if (G[u][v] == '1') {
            if (P[v] == -1) p = min(p, dfs(v));
            else if (!F[v]) p = min(p, P[v]);
        }
    }

    if (p == P[u]) {
        int c = 1e9;
        while (1) {
            int v = S.top(); S.pop();
            c = min(c, C[v]);
            F[v] = 1;
            if (u == v) break;
        }
        ans += c;
    }

    return p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) cin >> G[i];

    memset(P, -1, sizeof P);
    memset(F, 0, sizeof F);
    for (int i = 0; i < N; i++)
        if (!F[i]) dfs(i);

    cout << ans << '\n';

    return 0;
}
