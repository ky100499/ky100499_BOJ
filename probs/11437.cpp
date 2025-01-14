#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5,
          MAXD = 17;

int P[MAX+1][MAXD] = {},
    D[MAX+1];
vector<int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    while (--N) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> q({1});
    fill(D, D+MAX+1, -1); D[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if (D[v] == -1) {
                D[v] = D[u]+1;
                P[v][0] = u;
                for (int i = 1; i < MAXD; i++) P[v][i] = P[P[v][i-1]][i-1];
                q.push(v);
            }
        }
    }

    int M; cin >> M;
    while (M--) {
        int a, b; cin >> a >> b;

        int d = D[a] - D[b];
        if (d < 0) {
            swap(a, b);
            d *= -1;
        }

        for (int i = 0; i < MAXD; i++)
            if (d & (1<<i))
                a = P[a][i];

        if (a != b) {
            for (int i = MAXD-1; i >= 0; i--) {
                if (P[a][i] != P[b][i]) {
                    a = P[a][i];
                    b = P[b][i];
                }
            }
            a = P[a][0];
        }
        cout << a << '\n';
    }

    return 0;
}
