#include <bits/stdc++.h>

using namespace std;
using ti = tuple<int, int, int>;

int A[15];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, L, R, X; cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ti> dp(1<<N, {0, 2e9, 0});
    for (int i = 0; i < N; i++) {
        dp[1<<i] = { A[i], A[i], A[i] };
    }

    int cnt = 0;
    for (int i = 1; i < 1<<N; i++) {
        int j = 1;
        while (!(i & j)) j <<= 1;
        if (i == j) continue;

        auto [s1, l1, r1] = dp[j];
        auto [s2, l2, r2] = dp[i^j];

        int s = s1+s2, l = min(l1, l2), r = max(r1, r2);
        dp[i] = { s, l, r };

        if (L <= s && s <= R && r - l >= X) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
