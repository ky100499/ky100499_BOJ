#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    cout << N << '\n';
    if (N%3 == 0) {
        for (int i = 1; i < N; i += 3)
            cout << i << ' ' << i+2 << ' ' << i+1 << ' ';
        cout << 1 << '\n';
    }
    else if (N%3 == 1) {
        for (int i = 1; i < N; i += 3)
            cout << i << ' ' << i+2 << ' ' << i+1 << ' ';
        cout << N << ' ' << 1 << '\n';
    }
    else if (N%3 == 2) {
        cout << 1 << ' ';
        for (int i = 2; i < N; i += 3)
            cout << i << ' ' << i+2 << ' ' << i+1 << ' ';
        cout << N << ' ' << 1 << '\n';
    }

    return 0;
}
