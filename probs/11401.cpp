#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 4e6,
          MOD = 1e9+7;

ll fact[MAX+1];

ll power(ll b, int p)
{
    if (p == 1) return b;

    ll x = power(b, p/2);
    if (p%2) return (x * x % MOD) * b % MOD;
    else return x * x % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++) fact[i] = fact[i-1]*i % MOD;

    cout << fact[N] * power(fact[K], MOD-2) % MOD * power(fact[N-K], MOD-2) % MOD << '\n';

    return 0;
}
