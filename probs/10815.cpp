#include <bits/stdc++.h>

using namespace std;

set<int> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    while (N--) {
        int n; cin >> n;
        S.insert(n);
    }

    int M; cin >> M;
    while (M--) {
        int n; cin >> n;
        if (S.find(n) == S.end()) cout << "0 ";
        else cout << "1 ";
    }
    cout << '\n';

    return 0;
}
