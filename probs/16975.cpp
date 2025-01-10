#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e5;

ll ST[4*MAX], lazy[4*MAX] = {};

void init(int i, int l, int h)
{
    if (l == h) cin >> ST[i];
    else {
        int m = (l+h)/2;
        init(2*i, l, m);
        init(2*i+1, m+1, h);
        ST[i] = ST[2*i] + ST[2*i+1];
    }
}

void lazyupdate(int i, int l, int h)
{
    if (lazy[i]) {
        ST[i] += lazy[i] * (h-l+1);
        if (l != h) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int i, int l, int h, int s, int e, int v)
{
    lazyupdate(i, l, h);
    if (e < l || h < s) return;
    else if (s <= l && h <= e) {
        lazy[i] += v;
        lazyupdate(i, l, h);
    }
    else {
        int m = (l+h)/2;
        update(2*i, l, m, s, e, v);
        update(2*i+1, m+1, h, s, e, v);
        ST[i] = ST[2*i] + ST[2*i+1];
    }
}

ll find(int i, int l, int h, int s, int e)
{
    lazyupdate(i, l, h);
    if (e < l || h < s) return 0;
    else if (s <= l && h <= e) return ST[i];
    else {
        int m = (l+h)/2;
        return find(2*i, l, m, s, e) + find(2*i+1, m+1, h, s, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    init(1, 1, N);
    int M; cin >> M;
    while (M--) {
        int q; cin >> q;
        if (q == 1) {
            int i, j, k; cin >> i >> j >> k;
            update(1, 1, N, i, j, k);
        }
        else {
            int x; cin >> x;
            cout << find(1, 1, N, x, x) << '\n';
        }
    }

    return 0;
}
