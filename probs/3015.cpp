#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    stack<pi> S;
    long long ans = 0;
    while (N--) {
        int h; cin >> h;
        int dup = 0;
        while (!S.empty() && S.top().first < h) {
            ans += S.top().second;
            S.pop();
        }
        if (!S.empty() && S.top().first == h) {
            ans += dup = S.top().second;
            S.pop();
        }
        if (!S.empty()) ans += 1;
        S.emplace(h, dup+1);
    }

    cout << ans << '\n';

    return 0;
}
