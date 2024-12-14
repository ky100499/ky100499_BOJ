#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5,
          MAXD = 17;

int depth[MAX+1],
    parent[MAX+1][MAXD],
    minl[MAX+1][MAXD],
    maxl[MAX+1][MAXD],
    V[MAX+1] = {};
map<int, int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }

    queue<int> q({1}); depth[1] = 0; V[1] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto [nxt, l] : G[cur]) {
            if (!V[nxt]) {
                depth[nxt] = depth[cur]+1;
                parent[nxt][0] = cur;
                minl[nxt][0] = maxl[nxt][0] = l;

                for (int i = 1; i < MAXD; i++) {
                    parent[nxt][i] = parent[parent[nxt][i-1]][i-1];
                    minl[nxt][i] = min(minl[nxt][i-1], minl[parent[nxt][i-1]][i-1]);
                    maxl[nxt][i] = max(maxl[nxt][i-1], maxl[parent[nxt][i-1]][i-1]);
                }

                V[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    int K; cin >> K;
    while (K--) {
        int x, y; cin >> x >> y;
        int d = depth[x] - depth[y];

        if (d < 0) tie(x, y, d) = make_tuple(y, x, -d);

        int ans_min = 1e6, ans_max = 0;
        for (int i = 0; i < MAXD; i++) {
            if (d & (1<<i)) {
                ans_min = min(ans_min, minl[x][i]);
                ans_max = max(ans_max, maxl[x][i]);
                x = parent[x][i];
            }
        }
        if (x != y) {
            for (int i = MAXD-1; i >= 0; i--) {
                if (parent[x][i] != parent[y][i]) {
                    ans_min = min(min(ans_min, minl[x][i]), minl[y][i]);
                    ans_max = max(max(ans_max, maxl[x][i]), maxl[y][i]);
                    x = parent[x][i];
                    y = parent[y][i];
                }
            }
            ans_min = min(min(ans_min, minl[x][0]), minl[y][0]);
            ans_max = max(max(ans_max, maxl[x][0]), maxl[y][0]);
        }

        cout << ans_min << ' ' << ans_max << '\n';
    }

    return 0;
}
