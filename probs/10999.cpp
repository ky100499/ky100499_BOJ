#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e6;

ll ST[4*MAX] = {}, lazy[4*MAX] = {};

void init(int i, int l, int h)
{
    if (l == h) cin >> ST[i];
    else {
        int m = (l+h)/2;
        init(i*2, l, m);
        init(i*2+1, m+1, h);
        ST[i] = ST[i*2] + ST[i*2+1];
    }
}

void lazyupdate(int i, int l, int h)
{
    if (lazy[i]) {
        ST[i] += lazy[i] * (h - l + 1);
        if (l != h) {
            lazy[i*2] += lazy[i];
            lazy[i*2+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int i, int l, int h, int s, int e, ll v)
{
    lazyupdate(i, l, h);

    if (e < l || h < s) return;
    else if (s <= l && h <= e) {
        ST[i] += v * (h - l + 1);
        if (l != h) {
            lazy[i*2] += v;
            lazy[i*2+1] += v;
        }
    }
    else {
        int m = (l+h)/2;
        update(i*2, l, m, s, e, v);
        update(i*2+1, m+1, h, s, e, v);
        ST[i] = ST[i*2] + ST[i*2+1];
    }
}

ll find(int i, int l, int h, int s, int e)
{
    lazyupdate(i, l, h);

    if (e < l || h < s) return 0;
    else if (s <= l && h <= e) return ST[i];
    else {
        int m = (l+h)/2;
        return find(i*2, l, m, s, e) + find(i*2+1, m+1, h, s, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    init(1, 1, N);

    M += K;
    while (M--) {
        int q; cin >> q;
        if (q == 1) {
            int s, e; ll v; cin >> s >> e >> v;
            update(1, 1, N, s, e, v);
        }
        else {
            int s, e; cin >> s >> e;
            cout << find(1, 1, N, s, e) << '\n';
        }
    }

    return 0;
}
