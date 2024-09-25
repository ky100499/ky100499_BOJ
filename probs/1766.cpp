#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<int> ord(N+1);
    vector<vector<int>> nxt(N+1);
    while (M--) {
        int a, b; cin >> a >> b;
        ord[b]++;
        nxt[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
        if (!ord[i]) pq.push(i);

    while (!pq.empty()) {
        int p = pq.top(); pq.pop();
        cout << p << ' ';

        for (int n : nxt[p])
            if (--ord[n] == 0) pq.push(n);
    }
    cout << '\n';

    return 0;
}
