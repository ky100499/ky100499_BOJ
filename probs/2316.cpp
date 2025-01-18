#include <bits/stdc++.h>

using namespace std;

const int MAX = 400*2,
          INF = 1e9;

int F[MAX+1][MAX+1],
    C[MAX+1][MAX+1],
    pre[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(F, 0, sizeof F);
    memset(C, 0, sizeof C);

    int N, P; cin >> N >> P;
    C[1][1+N] = INF;
    for (int i = 2; i <= N; i++) C[i][i+N] = 1;
    while (P--) {
        int u, v; cin >> u >> v;
        C[u+N][v] = C[v+N][u] = 1;
    }

    while (1) {
        memset(pre, -1, sizeof pre);
        queue<int> q({1});
        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (u == 2) break;

            for (int v = 1; v <= 2*N; v++) {
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
    }
    cout << F[1][1+N] << '\n';

    return 0;
}
