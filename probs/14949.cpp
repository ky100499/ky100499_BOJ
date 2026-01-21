#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll A[6][201], F[401];

int power(ll b, int e)
{
    ll r = 1;
    while (e) {
        if (e&1) r = r * b % MOD;
        b = b*b % MOD;
        e >>= 1;
    }

    return r;
}

int C(int n, int k)
{
    return (F[n] * power(F[k], MOD-2) % MOD) * power(F[n-k], MOD-2) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int H, W; cin >> H >> W;
    F[0] = 1; for (int i = 1; i <= 2*W; i++) F[i] = (F[i-1] * i) % MOD;

    memset(A, 0, sizeof A); A[0][1] = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 1; k <= W; k++) {
                A[i][j] += A[i-1][k] * C(j+k-1, j);
                A[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= W; i++) ans = (ans + A[H][i]) % MOD;
    cout << ans << '\n';

    return 0;
}
