#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    stack<pi> S;

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int h; cin >> h;
        while (!S.empty() && S.top().second <= h) {
            ans += i - S.top().first - 1;
            S.pop();
        }
        S.emplace(i, h);
    }
    while (!S.empty()) {
        ans += N - S.top().first;
        S.pop();
    }

    cout << ans << '\n';

    return 0;
}
