#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int P, Q;
map<int, ll> A;

ll solve(ll n)
{
    if (n == 0) return 1;
    return A.find(n) == A.end() ? A[n] = solve(n/P) + solve(n/Q) : A[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll N; cin >> N >> P >> Q;
    cout << solve(N) << '\n';

    return 0;
}
