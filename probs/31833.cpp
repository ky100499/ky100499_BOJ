#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string X, Y;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        X += s;
    }
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        Y += s;
    }

    if (X.size() > Y.size()) cout << Y << '\n';
    else if (X.size() < Y.size()) cout << X << '\n';
    else cout << min(X, Y) << '\n';

    return 0;
}
