#include <bits/stdc++.h>

using namespace std;

const int MAX = 302,
          SRC = 0,
          SNK = 301,
          FOOD = 200;

int F[MAX][MAX],
    C[MAX][MAX],
    pre[MAX];
vector<int> G[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(F, 0, sizeof F);
    memset(C, 0, sizeof C);

    int N, K, D; cin >> N >> K >> D;
    for (int i = 1; i <= D; i++) {
        int c; cin >> c;
        C[FOOD+i][SNK] = c;
        G[FOOD+i].push_back(SNK);
    }
    for (int i = 1; i <= N; i++) {
        int z; cin >> z;
        while (z--) {
            int f; cin >> f;
            C[SRC][i] = K;
            C[i][FOOD+f] = 1;
            G[SRC].push_back(i);
            G[i].push_back(FOOD+f);
            G[FOOD+f].push_back(i);
        }
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
