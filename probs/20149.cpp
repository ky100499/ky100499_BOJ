#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const double ERR = 1e-8;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll a = (y2-y1) * (x3-x1) - (x2-x1) * (y3-y1),
       b = (y2-y1) * (x4-x1) - (x2-x1) * (y4-y1);

    if (a == 0 && b == 0) {
        if (x1 == x3 && y1 == y3 && (x1-x2) * (x3-x4) <= 0 && (y1-y2) * (y3-y4) <= 0)
            cout << "1\n" << x1 << ' ' << y1 << '\n';
        else if (x1 == x4 && y1 == y4 && (x1-x2) * (x4-x3) <= 0 && (y1-y2) * (y4-y3) <= 0)
            cout << "1\n" << x1 << ' ' << y1 << '\n';
        else if (x2 == x3 && y2 == y3 && (x2-x1) * (x3-x4) <= 0 && (y2-y1) * (y3-y4) <= 0)
            cout << "1\n" << x2 << ' ' << y2 << '\n';
        else if (x2 == x4 && y2 == y4 && (x2-x1) * (x4-x3) <= 0 && (y2-y1) * (y4-y3) <= 0)
            cout << "1\n" << x2 << ' ' << y2 << '\n';
        else if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
            cout << "1\n";
        else
            cout << "0\n";
    }
    else if (a == 0) {
        if (min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2))
            cout << "1\n" << x3 << ' ' << y3 << '\n';
        else
            cout << "0\n";
    }
    else if (b == 0) {
        if (min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y1, y2) <= y4 && y4 <= max(y1, y2))
            cout << "1\n" << x4 << ' ' << y4 << '\n';
        else
            cout << "0\n";
    }
    else if (a > 0 && b > 0 || a < 0 && b < 0) {
        cout << "0\n";
    }
    else {
        cout << fixed;
        cout.precision(20);
        double r = (double) abs(a) / (abs(a) + abs(b));
        double x = (1-r)*x3 + r*x4,
               y = (1-r)*y3 + r*y4;
        if (min(x1, x2)-ERR <= x && x <= max(x1, x2)+ERR && min(y1, y2)-ERR <= y && y <= max(y1, y2)+ERR)
            cout << "1\n" << x << ' ' << y << '\n';
        else
            cout << "0\n";
    }

    return 0;
}
