#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

map<pi, int> M;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    while (N--) {
        int x, y, d; cin >> x >> y;
        d = abs(gcd(x, y));
        M[{x/d, y/d}]++;
    }

    int ans = 0;
    for (auto& [k, v] : M) ans = max(ans, v);
    cout << ans << '\n';

    return 0;
}
