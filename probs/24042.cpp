#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>

#define INF 1e13

typedef long long ll;

using namespace std;
using pi = pair<ll, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<vector<pi>> G(N+1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back({i, b});
        G[b].push_back({i, a});
    }

    vector<ll> dist(N+1, INF);
    dist[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push({0, 1});
    while (!pq.empty()) {
        ll sd; int s; tie(sd, s) = pq.top(); pq.pop();

        if (s == N) {
            cout << sd << '\n';
            break;
        }

        if (dist[s] < sd) continue;

        for (auto [td, t] : G[s]) {
            ll nd;
            if (td < sd%M) nd = (sd/M+1)*M + td + 1;
            else nd = sd/M*M + td + 1;

            if (dist[t] > nd) {
                dist[t] = nd;
                pq.push({nd, t});
            }
        }
    }

    return 0;
}
