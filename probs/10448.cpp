#include <bits/stdc++.h>

using namespace std;

int T[3][1001] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int s = 0;
    for (int i = 1; s <= 1000; i++) {
        s += i;
        T[0][s] = 1;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i/2; j++) {
            if (T[0][j] && T[0][i-j]) {
                T[1][i] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            if (T[0][j] && T[1][i-j]) {
                T[2][i] = 1;
                break;
            }
        }
    }

    int N; cin >> N;
    while (N--) {
        int k; cin >> k;
        cout << T[2][k] << '\n';
    }

    return 0;
}
