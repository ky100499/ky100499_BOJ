#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int D[MAX+1], ord[MAX+1], T[MAX+1];
vector<int> nxt[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
            nxt[i].clear();
            ord[i] = 0;
            T[i] = D[i];
        }
        while (K--) {
            int x, y; cin >> x >> y;
            nxt[x].push_back(y);
            ord[y]++;
        }
        int W; cin >> W;

        queue<int> q;
        for (int i = 1; i <= N; i++)
            if (!ord[i]) q.emplace(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (u == W) {
                cout << T[u] << '\n';
                break;
            }

            for (int v : nxt[u]) {
                T[v] = max(T[v], T[u]+D[v]);
                if (--ord[v] == 0) q.push(v);
            }
        }
    }

    return 0;
}
