#include <bits/stdc++.h>

using namespace std;

map<string, int> deg;
map<string, vector<string>> tree;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        deg[s]; tree[s];
    }
    int M; cin >> M;
    while (M--) {
        string X, Y; cin >> X >> Y;
        deg[X]++;
        tree[Y].push_back(X);
    }

    vector<string> ans;
    for (auto [k, v] : deg)
        if (!v) ans.push_back(k);
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (string a : ans) cout << a << ' ';
    cout << '\n';

    for (auto [k, v] : tree) {
        cout << k << ' ';

        ans.clear();
        for (string child : v) {
            if (deg[k]+1 == deg[child]) ans.push_back(child);
        }
        sort(ans.begin(), ans.end());

        cout << ans.size() << ' ';
        for (string a : ans) cout << a << ' ';
        cout << '\n';
    }

    return 0;
}
