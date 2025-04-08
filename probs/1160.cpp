#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

ll m, a, c, x, n, g;

ll mul(ll a, ll b)
{
    ll c = 0;
    while (a) {
        if (a&1) c = (b+c)%m;
        b = (b+b) % m;
        a >>= 1;
    }
    return c;
}

vvl mat_mul(vvl a, vvl b)
{
    vvl c(2, vl(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + mul(a[i][k], b[k][j])) % m;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> m >> a >> c >> x >> n >> g;

    vvl ans({{1,0}, {0,1}}), mat({{a, c}, {0, 1}});
    while (n) {
        if (n&1) ans = mat_mul(ans, mat);
        mat = mat_mul(mat, mat);
        n >>= 1;
    }

    ans = mat_mul(ans, vvl({{x,0}, {1,0}}));
    cout << ans[0][0] % g << '\n';

    return 0;
}
