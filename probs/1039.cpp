#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string N; int K; cin >> N >> K;

    queue<pair<string, int>> q; q.emplace(N, 0);
    string ans = "-1"; int l = N.size();
    map<string, vector<int>> V; V[N].resize(K+1);
    while (!q.empty()) {
        auto [s, k] = q.front(); q.pop();

        if (V[s][k]) continue;
        V[s][k] = 1;

        if (k == K) {
            ans = max(ans, s);
            continue;
        }

        for (int i = 0; i < l; i++) {
            for (int j = i+1; j < l; j++) {
                swap(s[i], s[j]);
                if (s[0] != '0') {
                    if (V.find(s) == V.end()) V[s].resize(K+1);
                    q.emplace(s, k+1);
                }
                swap(s[i], s[j]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
