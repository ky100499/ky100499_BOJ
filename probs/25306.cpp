#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n)
{
    switch (n%4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll A, B; cin >> A >> B;
    cout << (solve(A-1) ^ solve(B)) << '\n';

    return 0;
}
