#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    long long ans = 0;
    for (char c : S) {
        ans *= 26;
        ans += c-'A'+1;
    }

    cout << ans << '\n';

    return 0;
}
