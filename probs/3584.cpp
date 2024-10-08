#include <bits/stdc++.h>

#define MAX 15

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        vector<int> isRoot(N+1, 1);

        map<int, vector<int>> G;
        for (int i = 1; i < N; i++) {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
            isRoot[b] = 0;
        }

        queue<int> q;

        for (int i = 1; i <= N; i++) {
            if (isRoot[i]) {
                q.push(i);
                break;
            }
        }

        vector<int> V(N+1); V[q.front()] = 1;
        vector<vector<int>> parent(N+1, vector<int>(MAX));
        vector<int> depth(N+1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int nxt : G[cur]) {
                if (!V[nxt]) {
                    parent[nxt][0] = cur;
                    depth[nxt] = depth[cur]+1;
                    for (int i = 1; i < MAX; i++) {
                        parent[nxt][i] = parent[parent[nxt][i-1]][i-1];
                    }
                    q.push(nxt);
                    V[nxt] = 1;
                }
            }
        }

        int a, b; cin >> a >> b;
        if (depth[a] > depth[b]) swap(a, b);

        int diff = depth[b] - depth[a];
        for (int i = 0; i < MAX; i++) {
            if (diff & (1<<i)) {
                b = parent[b][i];
            }
        }

        if (a != b) {
            for (int i = MAX-1; i >= 0; i--) {
                if (parent[a][i] != parent[b][i]) {
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            a = parent[a][0];
        }

        cout << a << '\n';
    }

    return 0;
}
