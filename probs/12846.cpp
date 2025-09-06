#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    stack<pair<int, int>> S; S.emplace(0, 0);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int T; cin >> T;

        int d = i;
        while (S.top().first > T) {
            d = S.top().second;
            ans = max(ans, S.top().first * (i - d));
            S.pop();
        }

        if (S.top().first < T) S.emplace(T, d);
    }

    while (!S.empty()) {
        auto [t, i] = S.top(); S.pop();
        ans = max(ans, t * (N-i+1));
    }

    cout << ans << '\n';

    return 0;
}
