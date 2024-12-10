#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1001,
          INF = 1e9;

int G[MAX][MAX];
string S[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        G[i][i] = 0;
        for (int j = 1; j < i; j++) {
            int d = 0;
            for (int k = 0; k < S[i].size(); k++) d += pow(S[i][k]-S[j][k], 2);
            G[i][j] = G[j][i] = d;
        }
    }
    int S, T; cin >> S >> T;

    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, S);
    vector<int> dist(N+1, INF); dist[S] = 0;
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();

        if (dist[s] < d) continue;
        if (s == T) break;

        for (int t = 1; t <= N; t++) {
            if (d+G[s][t] < dist[t]) {
                dist[t] = d+G[s][t];
                pq.emplace(d+G[s][t], t);
            }
        }
    }

    cout << dist[T] << '\n';

    return 0;
}
