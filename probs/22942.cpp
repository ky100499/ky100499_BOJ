#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

vector<pi> A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N; A.reserve(N);
    for (int i = 0; i < N; i++) {
        int x, r; cin >> x >> r;
        A.emplace_back(x-r, x+r);
    }
    sort(A.begin(), A.end());

    stack<pi> S;
    bool ans = 1;
    for (auto [p, q] : A) {
        while (!S.empty() && S.top().second < p) S.pop();

        if (S.empty() || (S.top().first != p && S.top().second != p && q < S.top().second)) S.emplace(p, q);
        else {
            ans = 0;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
