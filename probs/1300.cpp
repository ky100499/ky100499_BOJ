#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    ll N, K; cin >> N >> K;

    ll l = 1, h = 1e10;
    while (l <= h) {
        ll m = (l+h)/2,
           lb = 0, ub = 0;
        for (int i = 1; i <= N; i++) {
            lb += min(N, (m-1)/i);
            ub += m <= i*N && m%i == 0;
        }
        ub += lb;

        if (K <= lb) h = m-1;
        else if (ub < K) l = m+1;
        else {
            cout << m << '\n';
            break;
        }
    }

    return 0;
}
