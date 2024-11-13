#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int>;

const int MAX = 1001;

vector<pi> G[MAX];
int V[MAX] = { 0, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }

    int ans = 0, cnt = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, 1);
    while (!pq.empty()) {
        if (cnt == N) break;

        auto [c, s] = pq.top(); pq.pop();
        if (!V[s]) {
            for (auto [t, w] : G[s]) pq.emplace(w, t);
            V[s] = 1;
            ans += c;
            cnt++;
        }
    }

    cout << ans << '\n';

    return 0;
}
