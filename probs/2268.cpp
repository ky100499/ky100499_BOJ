#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e6;

ll ST[4*MAX];

void modify(int i, int l, int h, int k, int v)
{
    if (l == h) ST[i] = v;
    else {
        int m = (l+h)/2;
        if (k <= m) modify(2*i, l, m, k, v);
        else modify(2*i+1, m+1, h, k, v);
        ST[i] = ST[2*i]+ST[2*i+1];
    }
}

ll sum(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) return ST[i];
    else if (e < l || h < s) return 0;
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

    int N, M; cin >> N >> M;
    memset(ST, 0, sizeof ST);
    while (M--) {
        int f, i, j; cin >> f >> i >> j;
        if (f) modify(1, 1, N, i, j);
        else cout << sum(1, 1, N, min(i, j), max(i, j)) << '\n';
    }

    return 0;
}
