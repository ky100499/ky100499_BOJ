#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    ll lb = -1, M = 0, r = 0;
    while (N--) {
        ll a, b; cin >> a >> b;
        if (r < -a) {
            ll charge = b - a - r;
            M = M ? gcd(M, charge) : charge;
            lb = max(lb, b);
            r = b;
        }
        else {
            r += a;
            if (r != b) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << (M > lb ? (M ? M : 1) : -1) << '\n';

    return 0;
}
