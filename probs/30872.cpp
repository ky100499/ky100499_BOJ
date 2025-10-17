#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 200001;

ll A[MAX], V[MAX], C[MAX], dp[MAX];
vector<int> G[MAX];

void solve(int u)
{
    V[u] = C[u] = 1;

    ll a = 0, b = 0;
    vector<ll> P;
    for (int v : G[u]) {
        if (V[v]) continue;
        solve(v);
        C[u] += C[v];
        if (C[v]%2) P.push_back(dp[v]);
        else if (dp[v] > 0) a += dp[v];
        else b += dp[v];
    }
    sort(P.begin(), P.end(), greater<ll>());

    dp[u] = A[u]-a;
    for (int i = 0; i < P.size(); i++)
        dp[u] += i%2 ? P[i] : -P[i];
    dp[u] += P.size()%2 ? b : -b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) cin >> A[i];

    memset(V, 0, sizeof V);
    solve(1);
    cout << (dp[1] == 0 ? "Draw" : dp[1] > 0 ? "Sehun" : "Cheolmin") << '\n';

    return 0;
}
