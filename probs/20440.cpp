#include <bits/stdc++.h>

using namespace std;

map<int, int> T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    while (N--) {
        int e, x; cin >> e >> x;
        T[e]++; T[x]--;
    }

    int n = 0, m = 0, b = 0, E, X;
    for (auto [k, v] : T) {
        n += v;
        if (n > m) {
            m = n;
            E = k;
            b = 1;
        }

        if (b && v < 0) {
            X = k;
            b = 0;
        }
    }

    cout << m << '\n';
    cout << E << ' ' << X << '\n';

    return 0;
}
