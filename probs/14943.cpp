#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    ll c = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        ans += abs(c);
        c += L;
    }

    cout << ans << '\n';

    return 0;
}
