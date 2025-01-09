#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const int MOD = 1e9+7;

vvl mul(vvl a, vvl b)
{
    vvl ret(2, vl(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ret;
}

vvl power(vvl b, ll p)
{
    if (p == 1) return b;

    vvl x = power(b, p/2);
    if (p%2) return mul(mul(x, x), b);
    else return mul(x, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N; cin >> N;
    vvl f(2, vl(2));
    f[0][0] = f[0][1] = f[1][0] = 1;
    f = power(f, N);
    cout << f[0][1] << '\n';

    return 0;
}
