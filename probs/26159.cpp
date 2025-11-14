#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e5+1,
          MOD = 1e9+7;

int N, C[MAX];
vector<int> G[MAX];
priority_queue<ll> A, B;

void dfs(int u, int p)
{
    C[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        C[u] += C[v];
        B.push((ll) C[v] * (N - C[v]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i < N; i++) {
        int n; cin >> n;
        A.push(-n);
    }

    dfs(1, 0);

    ll ans = 0;
    for (int i = 0; i < N-1; i++) {
        ll a = A.top(), b = B.top(); A.pop(); B.pop();
        ans = (ans - a * b) % MOD;
    }
    cout << ans << '\n';

    return 0;
}
