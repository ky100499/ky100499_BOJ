#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using mii = map<int, ll>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, S; cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    mii LS, RS;
    for (int i = 0; i < N/2; i++) {
        mii tmp(LS);
        for (auto [k, v] : LS) tmp[k+A[i]] += v;
        tmp[A[i]]++;
        LS = tmp;
    }
    for (int i = N/2; i < N; i++) {
        mii tmp(RS);
        for (auto [k, v] : RS) tmp[k+A[i]] += v;
        tmp[A[i]]++;
        RS = tmp;
    }

    // for (auto [k, v] : LS) cout << k << ' ' << v << '\n';
    // for (auto [k, v] : RS) cout << k << ' ' << v << '\n';

    ll cnt = LS[S] + RS[S];
    for (auto [k, v] : LS) cnt += v * RS[S-k];

    cout << cnt << '\n';

    return 0;
}
