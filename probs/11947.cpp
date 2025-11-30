#include <bits/stdc++.h>

using namespace std;

string F(string S)
{
    string ret = "";
    for (char c : S) ret += '9'-c+'0';
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;

        if (s[0] >= '5') s = '5' + string(s.size()-1, '0');
        cout << stoll(s) * stoll(F(s)) << '\n';
    }

    return 0;
}
