#include <bits/stdc++.h>

using namespace std;

vector<int> P[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int d, r; cin >> d >> r;
        P[d].push_back(r);
    }

    priority_queue<int> pq;
    int ans = 0;
    for (int i = N; i; i--) {
        for (int r : P[i]) pq.push(r);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';

    return 0;
}
