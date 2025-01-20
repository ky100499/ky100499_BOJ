#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

ll op(pi a, pi b)
{
    return a.first*b.second - a.second*b.first;
}

int ccw(pi a, pi b, pi c)
{
    ll z = op({b.first-a.first, b.second-a.second}, {c.first-b.first, c.second-b.second});
    return z > 0 ? 1 : z < 0 ? -1 : 0;
}

bool cross(pi a, pi b, pi c, pi d)
{
    int c1 = ccw(a, b, c) * ccw(a, b, d),
        c2 = ccw(c, d, a) * ccw(c, d, b);

    if (c1 == 0 && c2 == 0)
        return min(a, b) <= max(c, d) && min(c, d) <= max(a, b);

    return c1 <= 0 && c2 <= 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    pi A[4];
    for (int i = 0; i < 4; i++) cin >> A[i].first >> A[i].second;

    cout << (cross(A[0], A[1], A[2], A[3]) ? 1 : 0) << '\n';

    return 0;
}
