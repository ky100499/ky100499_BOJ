#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    char c;
    stack<char> C;
    bool rev = 1;
    while (scanf("%c", &c) == 1) {
        if (c == '\n') break;
        else if (c == '<' || c == '>') {
            while (!C.empty()) {
                cout << C.top(); C.pop();
            }
            rev = c == '>';
            cout << c;
        }
        else if (c == ' ') {
            while (!C.empty()) {
                cout << C.top(); C.pop();
            }
            cout << ' ';
        }
        else if (rev) C.push(c);
        else cout << c;
    }
    while (!C.empty()) {
        cout << C.top(); C.pop();
    }
    cout << '\n';

    return 0;
}
