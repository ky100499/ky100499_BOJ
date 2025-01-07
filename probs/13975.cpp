#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int K; cin >> K;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while (K--) {
            ll a; cin >> a;
            pq.push(a);
        }

        ll ans = 0;
        while (pq.size() > 1) {
            ll s = pq.top(); pq.pop();
            s += pq.top(); pq.pop();
            ans += s;
            pq.push(s);
        }

        cout << ans << '\n';
    }

    return 0;
}
