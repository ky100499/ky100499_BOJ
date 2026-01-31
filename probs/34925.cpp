#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll H, S; cin >> H >> S;
    if (H > 4) cout << (H+S*3+1) / 2 << '\n';
    else if (H > 2) cout << S+2 << '\n';
    else cout << "1\n";

    return 0;
}
