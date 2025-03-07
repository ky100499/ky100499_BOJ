#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int ST[MAX*4];

void init(int i, int l, int h)
{
    if (l == h) {
        cin >> ST[i];
        ST[i] %= 2;
    }
    else {
        int m = (l+h)/2;
        init(i*2, l, m);
        init(i*2+1, m+1, h);
        ST[i] = ST[i*2]+ST[i*2+1];
    }
}

void update(int i, int l, int h, int k, int v)
{
    if (l == h) ST[i] = v%2;
    else {
        int m = (l+h)/2;
        if (k <= m) update(i*2, l, m, k, v);
        else update(i*2+1, m+1, h, k, v);
        ST[i] = ST[i*2]+ST[i*2+1];
    }
}

int query(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) return ST[i];
    else if (e < l || h < s) return 0;
    else {
        int m = (l+h)/2;
        return query(i*2, l, m, s, e) + query(i*2+1, m+1, h, s, e);
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
        int q, i, x; cin >> q >> i >> x;
        if (q == 1) update(1, 1, N, i, x);
        else if (q == 2) cout << (x-i+1) - query(1, 1, N, i, x) << '\n';
        else if (q == 3) cout << query(1, 1, N, i, x) << '\n';
    }

    return 0;
}
