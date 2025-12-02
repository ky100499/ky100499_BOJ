#include <bits/stdc++.h>

using namespace std;

int A[9];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 9; i++) cin >> A[i];

    int d = 0, w = 0;
    for (int i = 0; i < 9; i++) {
        d += A[i];
        w |= d > 0;
        int b; cin >> b;
        d -= b;
        w |= d > 0;
    }

    cout << (w ? "Yes" : "No") << '\n';

    return 0;
}
