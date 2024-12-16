#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, int>;

const int MAX = 2e5;
const ll INF = 1e18;

ll dist[MAX+1];
bool ans[MAX+1] = {};
vector<int> hist[MAX+1];
map<int, int> G[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, A, B; cin >> N >> M >> A >> B;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, A);
    for (int i = 1; i <= N; i++) dist[i] = INF; dist[A] = 0;
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;
        if (s == B) break;

        for (auto [t, w] : G[s]) {
            if (dist[t] > d+w) {
                dist[t] = d+w;
                hist[t] = vector<int>({s});
                pq.emplace(d+w, t);
            }
            else if (dist[t] == d+w) hist[t].push_back(s);
        }
    }

    queue<int> q({B}); ans[B] = 1;
    int cnt = 1;
    while (!q.empty()) {
        int n = q.front(); q.pop();
        for (int p : hist[n]) {
            if (!ans[p]) {
                ans[p] = 1;
                cnt++;
                q.push(p);
            }
        }
    }

    cout << cnt << '\n';
    for (int i = 1; i <= N; i++)
        if (ans[i]) cout << i << ' ';
    cout << '\n';

    return 0;
}
