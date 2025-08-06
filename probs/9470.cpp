#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

int deg[MAX], ord[MAX], maxord[MAX];
vector<int> nxt[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int K, M, P; cin >> K >> M >> P;
        for (int i = 1; i <= M; i++) {
            deg[i] = 0;
            ord[i] = 1;
            maxord[i] = 0;
            nxt[i].clear();
        }
        while (P--) {
            int a, b; cin >> a >> b;
            deg[b]++;
            nxt[a].push_back(b);
        }

        queue<int> q;
        for (int i = 1; i <= M; i++)
            if (!deg[i]) q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : nxt[u]) {
                if (maxord[v] == ord[u])
                    ord[v] = ord[u] + 1;
                else if (maxord[v] < ord[u])
                    maxord[v] = ord[v] = ord[u];

                if (!--deg[v]) q.push(v);
            }
        }

        cout << K << ' ' << ord[M] << '\n';
    }

    return 0;
}
