#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9,
          MAX = 1000;

int G[MAX][MAX];
bool C[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> G[i][j];

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, 0, 0);
    vector<vector<int>> dist(N, vector<int>(N, INF)); dist[0][0] = 0;
    while (!pq.empty()) {
        auto [tr, ti, s] = pq.top(); pq.pop();

        if (dist[s][tr] < ti) continue;

        if (s == M) {
            cout << tr << ' ' << ti << '\n';
            break;
        }

        for (int i = 0; i < N; i++) {
            if (!G[s][i]) continue;

            int _tr = tr + (C[s]^C[i]), _ti = ti + G[s][i];
            if (dist[i][_tr] > _ti) {
                dist[i][_tr] = _ti;
                pq.emplace(_tr, _ti, i);
            }
        }
    }

    return 0;
}
