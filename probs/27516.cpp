#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

ll gcd(ll a, ll b)
{
    while (b)
        tie(a, b) = make_pair(b, a%b);
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll X, Y, N; cin >> X >> Y >> N;
    map<pi, ll> cnt;
    while (N--) {
        ll x, y; cin >> x >> y;
        ll dx = X-x, dy = Y-y; dx *= dx;
        if (dx == 0 || dy <= 0) continue;
        ll g = gcd(dx, dy);
        cnt[{dx/g*(X-x<0 ? -1 : 1), dy/g}]++;
    }
    // for (auto [k, v] : cnt)
    //     cout << '[' << k.first << ", " << k.second << "] : " << v << '\n';
    cout << (cnt.size() ? max_element(cnt.begin(), cnt.end(), [](pair<pi, ll> a, pair<pi, ll> b) { return a.second < b.second; })->second : 0) << '\n';

    return 0;
}
