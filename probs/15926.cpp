#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    stack<int> S; S.push(-1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == '(') S.push(i);
        else if (S.size() > 1) S.pop(), ans = max(ans, i-S.top());
        else S.top() = i;
    }

    cout << ans << '\n';

    return 0;
}
