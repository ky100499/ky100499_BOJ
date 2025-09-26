#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 2e5;

ll S[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    ll e = 0, o = -1e18, ans = -1e18; S[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        S[i] = S[i-1] + (i%2 ? S[i] : -S[i]);

        ans = max(ans, max(S[i]-e, o-S[i]));

        if (i%2) o = max(o, S[i]);
        else e = min(e, S[i]);
    }

    cout << ans << '\n';

    return 0;
}
