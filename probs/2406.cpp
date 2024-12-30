#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1e3;

int adj[MAX+1][MAX+1],
    V[MAX+1] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<pi> con(M);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        con[i] = {a, b};
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> adj[i][j];
    for (auto [a, b] : con) adj[a][b] = adj[b][a] = 0;

    int cnt = 0, X = 0;
    vector<pi> ans;
    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, 2, 0);
    while (!pq.empty() && cnt < N-1) {
        auto [w, n, p] = pq.top(); pq.pop();

        if (V[n]) continue;
        V[n] = 1;
        cnt++;

        if (w) {
            X += w;
            ans.emplace_back(n, p);
        }

        for (int i = 2; i <= N; i++)
            if (!V[i]) pq.emplace(adj[n][i], i, n);
    }

    cout << X << ' ' << ans.size() << '\n';
    for (auto [u, v] : ans) cout << u << ' ' << v << '\n';

    return 0;
}
