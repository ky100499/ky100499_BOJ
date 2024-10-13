#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    set<int> S;
    while (N--) {
        int a; cin >> a;
        S.insert(a);
    }

    for (auto s : S) cout << s << ' '; cout << '\n';

    return 0;
}
