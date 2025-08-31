#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    int ans = 0, n = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') n++;
        else if (S[i-1] == '(') ans += --n;
        else ans++, n--;
    }
    cout << ans << '\n';

    return 0;
}
