#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<pi> S; S.reserve(N);
    vector<int> ans; ans.reserve(2*N);
    for (int i = 1; i <= N; i++) {
        int s; cin >> s;
        S.emplace_back(s, i);
    }
    sort(S.begin(), S.end());

    int w = 0, r = 0;
    while (1) {
        if (S[r].first == 0) ans.push_back(S[r++].second);
        else break;
        if (r == N) break;

        while (w < N && S[w].first == 0) w++;
        if (w < N) {
            S[w].first--;
            ans.push_back(S[w].second);
        }
        else break;
    }

    if (ans.size() == 2*N-1)
        for (int a : ans)
            cout << a << '\n';
    else cout << "-1\n";

    return 0;
}
