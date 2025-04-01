#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int D, P, Q; cin >> D >> P >> Q;
    if (P < Q) swap(P, Q);

    int p = 0, ans = (P - D%P) % P;
    while (p < Q) {
        int R = D - P*p;
        if (R < 0) break;

        ans = min(ans, (Q - R%Q) % Q);
        p++;
    }

    cout << D+ans << '\n';

    return 0;
}
