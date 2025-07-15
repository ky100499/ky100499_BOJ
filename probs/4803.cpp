#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 500;

vector<int> G[MAX+1];
int V[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T = 0;
    while (++T) {
        int N, M; cin >> N >> M;
        if (N == 0) break;

        memset(V, 0, sizeof V);
        for (int i = 1; i <= N; i++) G[i].clear();

        while (M--) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (V[i]) continue;

            int t = 1;
            queue<pi> q; q.emplace(0, i);
            while (!q.empty()) {
                auto [p, c] = q.front(); q.pop();

                for (auto n : G[c]) {
                    if (n == p) continue;
                    if (V[n]) t = 0;
                    else {
                        V[n] = 1;
                        q.emplace(c, n);
                    }
                }
            }
            ans += t;
        }

        cout << "Case " << T << ": ";
        if (ans == 0) cout << "No trees.";
        else if (ans == 1) cout << "There is one tree.";
        else cout << "A forest of " << ans << " trees.";
        cout << '\n';
    }

    return 0;
}
