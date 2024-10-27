#include <bits/stdc++.h>

using namespace std;

pair<int, int> cl[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int s, t; cin >> s >> t;
        cl[i] = {s, t};
    }
    sort(cl, cl+N);

    priority_queue<int, vector<int>, greater<int>> pq; pq.push(0);
    for (int i = 0; i < N; i++) {
        if (pq.top() <= cl[i].first) pq.pop();
        pq.push(cl[i].second);
    }
    cout << pq.size() << '\n';

    return 0;
}
