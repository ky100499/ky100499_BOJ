#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 101;

vector<pi> G[MAX];
int ord[MAX], qty[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    memset(ord, 0, sizeof ord);
    while (M--) {
        int x, y, k; cin >> x >> y >> k;
        G[x].emplace_back(y, k);
        ord[y]++;
    }

    memset(qty, 0, sizeof qty); qty[N] = 1;
    queue<int> q({N});
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, w] : G[u]) {
            qty[v] += qty[u] * w;
            if (--ord[v] == 0) q.push(v);
        }

        if (!G[u].empty()) qty[u] = 0;
    }

    for (int i = 1; i <= N; i++)
        if (qty[i]) cout << i << ' ' << qty[i] << '\n';

    return 0;
}
