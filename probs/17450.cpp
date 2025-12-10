#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int a; double m = 0;
    for (int i = 0; i < 3; i++) {
        int p, w; cin >> p >> w;
        p *= 10; w *= 10;
        double r = (double) w / (p < 5000 ? p : p-500);
        if (m < r) a = i, m = r;
    }

    cout << "SNU"[a] << '\n';

    return 0;
}
