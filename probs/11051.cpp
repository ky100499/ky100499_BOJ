#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000,
          MOD = 10007;

int memo[MAX+1][MAX+1];

int comb(int n, int r)
{
    if (memo[n][r]) return memo[n][r];
    else if (r == 0 || n == r) return memo[n][r] = 1;
    else return memo[n][r] = (comb(n-1, r-1) + comb(n-1, r)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    cout << comb(N, K) << '\n';

    return 0;
}
