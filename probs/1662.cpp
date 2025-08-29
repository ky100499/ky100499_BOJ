#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;

    stack<pi> ST;
    int l = 0, n;
    for (char c : S) {
        if (c == '(') {
            ST.emplace(l-1, n);
            l = 0;
        }
        else if (c == ')') {
            auto [_l, _n] = ST.top(); ST.pop();
            l = _l + _n * l;
            n = _n;
        }
        else {
            l++;
            n = c - '0';
        }
    }
    cout << l << '\n';

    return 0;
}
