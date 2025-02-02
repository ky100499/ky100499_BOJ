#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 500;

int R[MAX],
    ans[MAX][MAX];
priority_queue<pi> C;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, s1 = 0, s2 = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> R[i];
        s1 += R[i];
    }
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        s2 += c;
        C.emplace(c, i);
    }

    if (s1 != s2) {
        cout << -1 << '\n';
        return 0;
    }

    memset(ans, 0, sizeof ans);
    for (int i = 0; i < N; i++) {
        vector<pi> tmp; tmp.reserve(R[i]);
        for (int j = 0; j < R[i]; j++) {
            auto [n, c] = C.top(); C.pop();
            if (n == 0) {
                cout << -1 << '\n';
                return 0;
            }
            ans[i][c] = 1;
            tmp.emplace_back(n-1, c);
        }
        for (pi c : tmp) C.push(c);
    }

    cout << 1 << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}
