#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 5e5;

int ST[4*MAX],
    ord[1000001];

void update(int i, int l, int h, int k)
{
    if (l == h) ST[i]++;
    else {
        int m = (l+h)/2;
        if (k <= m) update(2*i, l, m, k);
        else update(2*i+1, m+1, h, k);
        ST[i] = ST[2*i]+ST[2*i+1];
    }
}

int sum(int i, int l, int h, int s, int e)
{
    if (h < s || e < l) return 0;
    else if (s <= l && h <= e) return ST[i];
    else {
        int m = (l+h)/2;
        return sum(2*i, l, m, s, e) + sum(2*i+1, m+1, h, s, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        ord[a] = i;
    }

    memset(ST, 0, sizeof ST);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        update(1, 1, N, ord[b]);
        ans += sum(1, 1, N, ord[b]+1, N);
    }

    cout << ans << '\n';

    return 0;
}
