#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

int cost[16][16],
    dp[1<<16],
    N, P;

int bit_count(int n)
{
    int ret = 0;
    while (n) {
        ret += n&1;
        n >>= 1;
    }
    return ret;
}

int dfs(int s)
{
    if (bit_count(s) >= P) return 0;

    if (dp[s] == INF) {
        for (int i = 0; i < N; i++) {
            if (s&(1<<i)) {
                for (int j = 0; j < N; j++) {
                    if (!(s&(1<<j))) {
                        dp[s] = min(dp[s], dfs(s|(1<<j))+cost[i][j]);
                    }
                }
            }
        }
    }
    return dp[s];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];
    string ipt; cin >> ipt;
    int state = 0;
    for (int i = 0; i < ipt.size(); i++) state |= (ipt[i] == 'Y') << i;
    cin >> P;

    fill(&dp[0], &dp[1<<16], INF);
    int ans = dfs(state);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}
