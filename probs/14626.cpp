#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    int m, s = 0;
    for (int i = 0; i < 13; i++) {
        if (S[i] == '*') m = i%2 ? 3 : 1;
        else s += (i%2 ? 3 : 1) * (S[i] - '0');
    }

    for (int i = 0; i < 10; i++) {
        if ((s + m*i) % 10 == 0) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
