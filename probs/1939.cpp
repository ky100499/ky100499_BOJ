#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 100000,
          INF = 2e9;

map<int, int> G[MAX+1];
int D[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        if (G[a].find(b) == G[a].end()) G[a][b] = G[b][a] = c;
        else G[a][b] = G[b][a] = max(G[a][b], c);
    }
    int A, B; cin >> A >> B;

    memset(D, 0, sizeof D); D[A] = INF;
    priority_queue<pi> pq; pq.emplace(INF, A);
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (D[s] > d) continue;
        if (s == B) {
            cout << d << '\n';
            break;
        }

        for (auto [t, w] : G[s]) {
            int nd = min(d, w);
            if (D[t] < nd) {
                D[t] = nd;
                pq.emplace(nd, t);
            }
        }
    }

    return 0;
}
