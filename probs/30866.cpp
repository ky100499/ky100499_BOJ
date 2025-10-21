#include <bits/stdc++.h>

using namespace std;

set<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    while (M--) {
        S.clear();
        int k; cin >> k;
        while (k--) {
            int a; cin >> a;
            if (S.find(-a) == S.end()) S.insert(a);
            else break;
        }
        if (k == -1) break;
        else while (k--) { int a; cin >> a; }
    }

    if (M != -1) {
        cout << "YES\n";
        for (int i = 1; i <= N; i++) {
            if (S.find(i) == S.end()) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
    else cout << "NO\n";

    return 0;
}
