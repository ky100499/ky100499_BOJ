#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll N; cin >> N;

    // S = a(r^n-1) / (r-1)
    ll r = 2;
    while (r <= 1e6) {
        ll K = 3, R = r*r*r;
        while (1) {
            ll s = (R-1) / (r-1);
            if (s > N) break;

            if (N % s == 0) {
                ll a = N / s;
                cout << K << '\n';
                for (int i = 0; i < K; i++) {
                    cout << a << ' ';
                    a *= r;
                }
                cout << '\n';
                return 0;
            }

            if (R > N) break;
            K++; R *= r;
        }
        r++;
    }

    cout << "-1\n";

    return 0;
}
