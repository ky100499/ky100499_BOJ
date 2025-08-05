#include <bits/stdc++.h>

using namespace std;

const int MAX = 501;

int deg[MAX], tmp[MAX];
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            int t; cin >> t;
            deg[t] = i;
        }
        memcpy(tmp, deg, sizeof tmp);
        int M; cin >> M;
        while (M--) {
            int a, b; cin >> a >> b;
            if (tmp[a] < tmp[b]) {
                deg[a]++;
                deg[b]--;
            }
            else {
                deg[a]--;
                deg[b]++;
            }
        }

        ans.clear(); ans.reserve(N);
        for (int d = 0; d < N; d++) {
            for (int i = 1; i <= N; i++) {
                if (deg[i] == d) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        if (ans.size() == N) {
            for (int i = 0; i < N; i++) cout << ans[i] << ' ';
            cout << '\n';
        }
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}
