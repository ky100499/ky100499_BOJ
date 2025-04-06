#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int S, P; cin >> S >> P;
    if (S == P) {
        cout << "1\n";
        return 0;
    }

    int ans = 2;
    while (ans <= S) {
        if (pow(1.0*S/ans, ans) >= P) {
            cout << ans << '\n';
            break;
        }
        ans++;
    }

    if (ans > S) cout << "-1\n";

    return 0;
}
