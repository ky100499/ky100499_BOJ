#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S, T; cin >> S >> T;

    int rev = 0, s = 0, e = T.size()-1;
    for (int i = T.size() - S.size(); i; i--) {
        if (rev) {
            if (T[s++] == 'B') rev = 0;
        }
        else {
            if (T[e--] == 'B') rev = 1;
        }
    }

    int ans = 1;
    for (int i = 0; i < S.size() && ans; i++) {
        if (rev) ans &= S[i] == T[e-i];
        else ans &= S[i] == T[s+i];
    }

    cout << ans << '\n';

    return 0;
}
