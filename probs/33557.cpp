#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        ll A, B, R; cin >> A >> B; R = A*B;

        string res = "";
        while (A && B) {
            res = to_string((A%10)*(B%10)) + res;
            A /= 10;
            B /= 10;
        }
        if (A) res = to_string(A) + res;
        if (B) res = to_string(B) + res;

        cout << (res == to_string(R)) << '\n';
    }

    return 0;
}
