#include <bits/stdc++.h>

using namespace std;

const int MAX = 200,
          INF = 1e9;

int F[MAX+1][MAX+1],
    C[MAX+1][MAX+1],
    pre[MAX+1];
vector<int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;

        // init
        memset(F, 0, sizeof F);
        memset(C, 0, sizeof C);
        for (int i = 1; i <= N; i++) G[i].clear();

        while (M--) {
            int x, y; cin >> x >> y;
            if (x > y) swap(x, y);
            G[x].push_back(y);
            G[y].push_back(x);
            C[x][y] = (x == 1 || y == N) ? 1 : INF;
        }

        int ans = 0;
        while (1) {
            memset(pre, -1, sizeof pre);
            queue<int> q({1});
            while (!q.empty()) {
                int u = q.front(); q.pop();

                if (u == N) break;

                for (int v : G[u]) {
                    if (pre[v] == -1 && C[u][v] > F[u][v]) {
                        pre[v] = u;
                        q.push(v);
                    }
                }
            }

            if (pre[N] == -1) break;

            int f = INF;
            for (int u = N; u != 1; u = pre[u])
                f = min(f, C[pre[u]][u]-F[pre[u]][u]);
            for (int u = N; u != 1; u = pre[u]) {
                F[pre[u]][u] += f;
                F[u][pre[u]] -= f;
            }
            ans += f;
        }

        cout << ans << '\n';
    }

    return 0;
}
