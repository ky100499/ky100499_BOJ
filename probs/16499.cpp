#include <bits/stdc++.h>

using namespace std;

set<string> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        S.insert(s);
    }

    cout << S.size() << '\n';

    return 0;
}
