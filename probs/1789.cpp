#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll S; cin >> S;

    int ans = 1;
    ll i = sqrt(S*2)-2;
    while (1) {
        if (i*(i+1)/2 > S) break;
        ans = i++;
    }

    cout << ans << '\n';

    return 0;
}
