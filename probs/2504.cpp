#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;

    stack<char> P;
    int m = 1, ans = 0, add = 0;
    for (char c : S) {
        if (c == '(') {
            P.push(c);
            m *= 2;
            add = 1;
        }
        else if (c == '[') {
            P.push(c);
            m *= 3;
            add = 1;
        }
        else if (c == ')' && !P.empty() && P.top() == '(') {
            P.pop();
            if (add) ans += m;
            m /= 2;
            add = 0;
        }
        else if (c == ']' && !P.empty() && P.top() == '[') {
            P.pop();
            if (add) ans += m;
            m /= 3;
            add = 0;
        }
        else {
            ans = 0;
            break;
        }
    }

    if (!P.empty()) ans = 0;

    cout << ans << '\n';

    return 0;
}
