#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

deque<pi> L, R;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        R.emplace_back(a, i);
    }

    while (R.size() > 1) {
        while (!R.empty()) {
            auto [x, i] = R.front(); R.pop_front();
            ll nx = x;
            if (!L.empty() && L.back().first <= x) {
                nx += L.back().first;
                L.pop_back();
            }
            if (!R.empty() && R.front().first <= x) {
                nx += R.front().first;
                R.pop_front();
            }
            L.emplace_back(nx, i);
        }
        swap(L, R);
    }

    auto [a, b] = R.front();
    cout << a << '\n' << b << '\n';

    return 0;
}
