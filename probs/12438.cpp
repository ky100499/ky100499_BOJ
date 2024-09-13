#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; ull M, DOM, DOW; cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> M >> DOM >> DOW;

        ull cycle_m = DOW / gcd(DOM, DOW),
            cycle_w = DOM / gcd(DOM, DOW),
            total = M * DOM;

        // 사이클 내 공백
        total += M / cycle_m * DOW * (cycle_m-1);

        // 사이클 이후 공백
        if (M % cycle_m)
            total += DOW * (M % cycle_m - 1);

        cout << "Case #" << i << ": " << (total - 1) / DOW + 1 << '\n';
    }

    return 0;
}
