#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

list<pi> L;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        L.emplace_back(a, i);
    }

    while (L.size() > 1) {
        for (auto it = L.begin(); it != L.end(); it++) {
            ll x = it->first;
            if (it != L.begin() && prev(it)->first <= x) {
                it->first += prev(it)->first;
                L.erase(prev(it));
            }
            if (next(it) != L.end() && next(it)->first <= x) {
                it->first += next(it)->first;
                L.erase(next(it));
            }
        }
    }

    cout << L.begin()->first << '\n' << L.begin()->second << '\n';

    return 0;
}
