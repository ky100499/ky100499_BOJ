#include <bits/stdc++.h>

using namespace std;

stack<int> S[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < 4; i++) S[i].push(0);

    bool ans = 1;
    while (N--) {
        int a, idx = -1, m = -1; cin >> a;
        for (int i = 0; i < 4; i++) {
            int t = S[i].top();
            if (t < a && t > m) idx = i, m = S[i].top();
        }

        if (idx == -1) {
            ans = 0;
            break;
        }
        else S[idx].push(a);
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
