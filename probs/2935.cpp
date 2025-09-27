#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string n, m; char o; cin >> n >> o >> m;

    if (o == '+') {
        if (n.size() < m.size()) swap(n, m);
        n[n.size()-m.size()]++;
    }
    else n = "1" + string(n.size() + m.size() - 2, '0');

    cout << n << '\n';

    return 0;
}
