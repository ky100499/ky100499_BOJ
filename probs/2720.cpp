#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int C; cin >> C;
        cout << C/25 << ' ';
        C %= 25;
        cout << C/10 << ' ';
        C %= 10;
        cout << C/5 << ' ';
        C %= 5;
        cout << C << '\n';
    }

    return 0;
}
