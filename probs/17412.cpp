#include <bits/stdc++.h>

using namespace std;

const int MAX = 400;

int F[MAX+1][MAX+1],
    C[MAX+1][MAX+1],
    pre[MAX+1];
vector<int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(F, 0, sizeof F);
    memset(C, 0, sizeof C);

    int N, P; cin >> N >> P;
    while (P--) {
        int u, v; cin >> u >> v;
        C[u][v] = 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    while (1) {
        memset(pre, -1, sizeof pre);
        queue<int> q({1});
        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (u == 2) break;

            for (int v : G[u]) {
                if (pre[v] == -1 && C[u][v] > F[u][v]) {
                    pre[v] = u;
                    q.push(v);
                }
            }
        }

        if (pre[2] == -1) break;

        for (int u = 2; u != 1; u = pre[u]) {
            F[pre[u]][u] += 1;
            F[u][pre[u]] -= 1;
        }
        ans += 1;
    }
    cout << ans << '\n';

    return 0;
}
