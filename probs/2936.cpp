#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    double x, y; cin >> x >> y;

    double X, Y;
    if (x == 0) {
        if (y < 125) {
            // -> 빗변
            // (250-y) * X = 250*250/2
            X = 62500.0 / 2 / (250-y);
            Y = 250 - X;
        }
        else {
            // -> 밑변
            // y * X = 250*250/2
            X = 62500.0 / 2 / y;
            Y = 0;
        }
    }
    else if (y == 0) {
        if (x < 125) {
            // -> 빗변
            // (250-x) * Y = 250*250/2
            Y = 62500.0 / 2 / (250-x);
            X = 250-Y;
        }
        else {
            // -> 높이
            // x * Y = 250*250/2
            Y = 62500.0 / 2 / x;
            X = 0;
        }
    }
    else {
        if (x < 125) {
            // -> 밑변
            // (250-X) * y = 250*250/2
            X = 250 - 62500.0 / 2 / y;
            Y = 0;
        }
        else {
            // -> 높이
            // (250-Y) * x = 250*250/2
            Y = 250 - 62500.0 / 2 / x;
            X = 0;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << X << ' ' << Y << '\n';

    return 0;
}
