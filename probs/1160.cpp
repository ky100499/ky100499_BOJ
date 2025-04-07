#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using lll = __int128;
using vl = vector<lll>;
using vvl = vector<vl>;

ll mm, aa, cc, xx, nn, gg;
lll m, a, c, x, n, g;

vvl mul(vvl a, vvl b)
{
    vvl c(2, vl(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> mm >> aa >> cc >> xx >> nn >> gg;
    m = mm; a = aa; c = cc; x = xx; n = nn; g = gg;

    vvl ans({{1,0}, {0,1}}), mat({{a, c}, {0, 1}});
    while (n) {
        if (n&1) ans = mul(ans, mat);
        mat = mul(mat, mat);
        n >>= 1;
    }

    ans = mul(ans, vvl({{x,0}, {1,0}}));
    cout << (ll)ans[0][0] % (ll)g << '\n';

    return 0;
}
