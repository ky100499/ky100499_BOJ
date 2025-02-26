#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const int MOD = 1e9+7;

int N, M;

vvl mul(vvl a, vvl b)
{
    vvl c(N, vl(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
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

    cin >> N >> M;
    vvl G(N, vl(N));
    while (M--) {
        int a, b; cin >> a >> b;
        G[a-1][b-1] = G[b-1][a-1] = 1;
    }

    int D; cin >> D;
    cout << power(G, D)[0][0] << '\n';

    return 0;
}
