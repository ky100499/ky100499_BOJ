#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

ll C[500001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    ll S = 0;
    while (N--) {
        int F; cin >> F;
        S += F;

        vector<pi> V1, V2;
        for (int x = 1;; x++) {
            int y = (F-1) / x + 1;
            if (x < y) {
                V1.emplace_back(x, y);
                V2.emplace_back(y, x);
            }
            else if (x == y) {
                V1.emplace_back(x, y);
                break;
            }
            else break;
        }

        for (auto v = V2.rbegin(); v != V2.rend(); v++) V1.emplace_back(*v);

        for (int i = 1; i < V1.size(); i++) C[V1[i].first] += V1[i-1].second - V1[i].second;
    }

    int T; cin >> T;

    ll a1 = 1e18, a2;
    for (int i = 1; i < 500001; i++) {
        S -= C[i];
        ll t = (T+i)*S;
        if (t < a1) a1 = t, a2 = i;
    }

    cout << a1 << ' ' << a2 << '\n';

    return 0;
}
