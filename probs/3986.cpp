#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T, ans = 0; cin >> T;
    while (T--) {
        string S; cin >> S;
        stack<char> C;
        for (char c : S) {
            if (!C.empty() && c == C.top()) C.pop();
            else C.push(c);
        }
        if (C.empty()) ans++;
    }

    cout << ans << '\n';

    return 0;
}
