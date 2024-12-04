#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

const int MAX = 1000;

int V[MAX], G[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, ipt; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> G[i][j];

    int cnt = 0; ll ans = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, 0);
    while (cnt < N) {
        auto [w, v] = pq.top(); pq.pop();

        if (V[v]) continue;
        V[v] = 1;
        ans += w;
        cnt++;

        for (int i = 0; i < N; i++) {
            if (!V[i]) pq.emplace(G[v][i], i);
        }
    }

    cout << ans << '\n';

    return 0;
}
