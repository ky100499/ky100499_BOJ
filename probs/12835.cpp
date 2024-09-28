#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; ll L; cin >> N >> L;
    int cnt[3] = { 0, }; ll ans = 0;
    map<ll, vector<char>> ants;

    while (N--) {
        char p; ll x; int d; cin >> p >> x >> d;
        if (d == 1) {
            cnt[p-'A']++;
            ans += L-x;
        }
        else {
            ants[x].push_back(p);
        }
    }

    for (auto [x, P] : ants) {
        if (P.size() == 1) {
            cnt[(P[0]-'A'+1)%3]++;
            ans += L+x;
        }
        else {
            for (char p : P) {
                cnt[p-'A']++;
                ans += L+x;
            }
        }
    }

    cout << ans << '\n';
    for (int c : cnt) cout << c << ' '; cout << '\n';

    return 0;
}
