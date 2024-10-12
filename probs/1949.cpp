#include <bits/stdc++.h>

using namespace std;

vector<int> ppl;
vector<vector<int>> G, dp;

int solve(int cur, int pre, int good)
{
    if (dp[cur][good]) return dp[cur][good];

    dp[cur][good] = good ? ppl[cur] : 0;
    for (int nxt : G[cur]) {
        if (nxt == pre) continue;
        if (good) dp[cur][good] += solve(nxt, cur, 0);
        else dp[cur][good] += max(solve(nxt, cur, 0), solve(nxt, cur, 1));
    }
    return dp[cur][good];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    ppl.resize(N+1); G.resize(N+1); dp.resize(N+1, vector<int>(2));
    for (int i = 1; i <= N; i++) cin >> ppl[i];
    while (--N) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << max(solve(1, 0, 0), solve(1, 0, 1)) << '\n';

    return 0;
}
