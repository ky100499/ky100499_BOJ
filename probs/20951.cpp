#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9+7;
int dp[100001][8] = {{0,},};

vector<vector<int>> G;

int solve(int node, int dist)
{
    if (dist == 7) return 1;
    else {
        if (!dp[node][dist]) {
            for (int next : G[node]) {
                dp[node][dist] = (dp[node][dist] + solve(next, dist+1)) % MOD;
            }
        }
        return dp[node][dist];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    G.resize(N+1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = (ans + solve(i, 0)) % MOD;
    cout << ans << '\n';

    return 0;
}
