#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    char a, b;
    while (1) {
        a = b; cin >> b;
        if (cin.eof() || b == '\n') break;

        if (a == '(' && b == ')') cout << 1;
        if (a == ')' && b == '(') cout << '+';
        cout << b;
    }
    cout << '\n';

    return 0;
}
