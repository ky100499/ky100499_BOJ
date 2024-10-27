#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int ans[MAX+1] = { 0, }, deg[MAX+1] = { 0, };
vector<int> nxt[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        deg[b]++;
        nxt[a].push_back(b);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (!deg[i]) q.push(i);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans[cur]++;

        for (int n : nxt[cur]) {
            ans[n] = max(ans[n], ans[cur]);
            if (--deg[n] == 0) q.push(n);
        }
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << ' '; cout << '\n';

    return 0;
}
