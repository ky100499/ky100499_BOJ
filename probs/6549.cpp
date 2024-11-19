#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

int A[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        int N; cin >> N;
        if (!N) break;
        for (int i = 0; i < N; i++) cin >> A[i];

        stack<pi> S;
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            int idx = i;
            while (!S.empty() && S.top().second >= A[i]) {
                auto [j, h] = S.top(); S.pop();
                ans = max(ans, (ll) (i - j) * h);
                idx = j;
            }
            S.emplace(idx, A[i]);
        }

        while (!S.empty()) {
            auto [j, h] = S.top(); S.pop();
            ans = max(ans, (ll) (N - j) * h);
        }

        cout << ans << '\n';
    }

    return 0;
}
