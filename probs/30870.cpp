#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 2e5+1;

int P[MAX], A[MAX];
vector<int> G[MAX];
stack<pi> S;

int find(int x)
{
    return P[x] == x ? x : P[x] = find(P[x]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    P[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    while (M--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q;
    while (K--) {
        int u; cin >> u;
        q.push(u);
    }

    memset(A, 0, sizeof A);
    int T = 0;
    while (!q.empty() && ++T) {
        for (int i = q.size(); i; i--) {
            int u = q.front(); q.pop();
            if (A[u]) continue;
            A[u] = 1;
            S.emplace(u, T);
            for (int v : G[u]) {
                if (!A[v]) q.push(v);
            }
        }
    }

    memset(A, 0, sizeof A);
    for (int i = 1; i <= N; i++) P[i] = i;

    while (!S.empty()) {
        auto [u, t] = S.top(); S.pop();

        if (A[u]) continue;
        A[u] = 1;

        for (int v : G[u]) {
            if (!A[v]) continue;

            if (find(u) == find(v)) {
                cout << t << '\n';
                while (!S.empty()) S.pop();
                break;
            }
            else merge(u, v);
        }
    }

    return 0;
}
