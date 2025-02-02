#include <bits/stdc++.h>

using namespace std;

const int MAX = 500,
          SRC = 0,
          SNK = 1000;

int F[2*MAX+1][2*MAX+1],
    C[2*MAX+1][2*MAX+1],
    pre[2*MAX+1];
vector<int> G[2*MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(F, 0, sizeof F);
    memset(C, 0, sizeof C);

    int N, s1 = 0, s2 = 0; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[SRC][i];
        G[SRC].push_back(i);
        s1 += C[SRC][i];
    }
    for (int i = N+1; i <= 2*N; i++) {
        cin >> C[i][SNK];
        G[i].push_back(SNK);
        s2 += C[i][SNK];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = N+1; j <= 2*N; j++) {
            C[i][j] = 1;
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }

    if (s1 != s2) {
        cout << -1 << '\n';
        return 0;
    }

    int s = 0;
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
        s += f;
    }

    if (s == s1) {
        cout << 1 << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = N+1; j <= 2*N; j++)
                cout << F[i][j];
            cout << '\n';
        }
    }
    else cout << -1 << '\n';

    return 0;
}
