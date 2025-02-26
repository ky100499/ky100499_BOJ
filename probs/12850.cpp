#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const int MOD = 1e9+7;

vvl G({
    { 0, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 1 },
    { 0, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 1, 0 },
});

vvl mul(vvl a, vvl b)
{
    vvl c(8, vl(8));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
    return c;
}

vvl power(vvl b, int e)
{
    if (e == 1) return b;

    vvl x = power(b, e/2);
    if (e%2) return mul(mul(x, x), b);
    else return mul(x, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int D; cin >> D;
    cout << power(G, D)[0][0] << '\n';

    return 0;
}
