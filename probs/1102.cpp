#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

int cost[16][16],
    dp[1<<16];

int bit_count(int n)
{
    int ret = 0;
    while (n) {
        ret += n&1;
        n >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];
    string ipt; cin >> ipt;
    int state = 0;
    for (int i = 0; i < ipt.size(); i++) state |= (ipt[i] == 'Y') << i;
    int P; cin >> P;

    fill(&dp[0], &dp[1<<16], INF); dp[state] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; pq.emplace(0, state);
    int ans = -1;
    while (!pq.empty()) {
        auto [c, s] = pq.top(); pq.pop();

        if (dp[s] < c) continue;
        if (bit_count(s) >= P) {
            ans = c;
            break;
        }

        for (int i = 0; i < N; i++) {
            if (s & (1<<i)) {
                int mcost = INF;
                vector<int> nxt;
                for (int j = 0; j < N; j++) {
                    int ns = s|(1<<j);
                    if (!(s & (1<<j)) && dp[ns] > c+cost[i][j]) {
                        dp[ns] = c+cost[i][j];
                        pq.emplace(c+cost[i][j], ns);
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
