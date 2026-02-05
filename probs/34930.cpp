#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int L, R, m; cin >> L >> R; m = max(L, (R+1)/2);
        cout << m << ' ';

        int s = -1;
        while (L <= R) {
            if (R != m) {
                cout << s * R << ' ';
                s *= -1;
            }
            R--;
        }
        cout << '\n';
    }

    return 0;
}
