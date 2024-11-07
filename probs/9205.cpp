#include <bits/stdc++.h>

#define dist(a, b) abs(a.first-b.first)+abs(a.second-b.second)

using namespace std;
using pi = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<pi> C(N+2);
        for (int i = 0; i < N+2; i++) cin >> C[i].first >> C[i].second;

        queue<int> q({0});
        vector<int> V(N+2); V[0] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();

            if (cur == N+1) break;

            for (int i = 0; i < N+2; i++) {
                if (!V[i] && dist(C[i], C[cur]) <= 1000) {
                    V[i] = 1;
                    q.push(i);
                }
            }
        }

        cout << (V[N+1] ? "happy" : "sad") << '\n';
    }

    return 0;
}
