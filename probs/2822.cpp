#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    pi pts[8];
    for (int i = 0; i < 8; i++) {
        int ipt; cin >> ipt;
        pts[i] = {ipt, i+1};
    }
    sort(pts, pts+8, [](pi x, pi y) {return x.first > y.first;});
    sort(pts, pts+5, [](pi x, pi y) {return x.second < y.second;});

    int s = 0;
    for (int i = 0; i < 5; i++) s += pts[i].first;
    cout << s << '\n';
    for (int i = 0; i < 5; i++) cout << pts[i].second << ' ';
    cout << '\n';

    return 0;
}
