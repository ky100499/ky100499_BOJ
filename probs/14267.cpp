#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int ans[MAX+1];
vector<int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int s; cin >> s;
        G[s].push_back(i);
    }
    memset(ans, 0, sizeof ans);

    while (M--) {
        int i, w; cin >> i >> w;
        ans[i] += w;
    }

    queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : G[u]) {
            ans[v] += ans[u];
            q.push(v);
        }
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
