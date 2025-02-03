#include <bits/stdc++.h>

using namespace std;

const int MAX = 2002,
          WORK = 1000,
          SRC = 0,
          SNK = 2001;

int F[MAX][MAX],
    C[MAX][MAX],
    pre[MAX];
vector<int> G[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(C, 0, sizeof C);
    memset(F, 0, sizeof F);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        C[SRC][i] = 2;
        G[SRC].push_back(i);

        int c; cin >> c;
        while (c--) {
            int w; cin >> w;
            C[i][w+WORK] = 1;
            G[i].push_back(w+WORK);
            G[w+WORK].push_back(i);
        }
    }
    for (int i = 1; i <= M; i++) {
        C[i+WORK][SNK] = 1;
        G[i+WORK].push_back(SNK);
    }

    int ans = 0;
    while (1) {
        memset(pre, -1, sizeof pre);
        queue<int> q({SRC});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == SNK) break;

            for (int v : G[u]) {
                if (pre[v] == -1 && C[u][v] > F[u][v]) {
                    pre[v] = u;
                    q.push(v);
                }
            }
        }

        if (pre[SNK] == -1) break;

        int f = 1e9;
        for (int u = SNK; u != SRC; u = pre[u])
            f = min(f, C[pre[u]][u] - F[pre[u]][u]);
        for (int u = SNK; u != SRC; u = pre[u]) {
            F[pre[u]][u] += f;
            F[u][pre[u]] -= f;
        }
        ans += f;
    }

    cout << ans << '\n';

    return 0;
}
