#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5;

int A[MAX], ans[MAX][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    memset(ans, 0, sizeof ans);
    stack<pi> S;
    for (int i = 0; i < N; i++) {
        while (!S.empty() && S.top().second <= A[i]) S.pop();
        if (!S.empty()) {
            ans[i][0] += S.size();
            ans[i][1] = S.top().first;
        }
        S.emplace(i, A[i]);
    }

    while (!S.empty()) S.pop();

    for (int i = N-1; i >= 0; i--) {
        while (!S.empty() && S.top().second <= A[i]) S.pop();
        if (!S.empty()) {
            if (ans[i][0] == 0) ans[i][1] = S.top().first;
            else if (i - ans[i][1] > S.top().first - i) ans[i][1] = S.top().first;
            ans[i][0] += S.size();
        }
        S.emplace(i, A[i]);
    }

    for (int i = 0; i < N; i++) {
        if (ans[i][0]) cout << ans[i][0] << ' ' << ans[i][1]+1 << '\n';
        else cout << "0\n";
    }

    return 0;
}
