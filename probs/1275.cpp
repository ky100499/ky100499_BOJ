#include <bits/stdc++.h>

using namespace std;

vector<long long> ST;

void update(int i, int l, int h, int k, int v)
{
    if (l == h) ST[i] = v;
    else {
        int m = (l+h)/2;
        if (k <= m) update(2*i, l, m, k, v);
        else update(2*i+1, m+1, h, k, v);
        ST[i] = ST[i*2] + ST[i*2+1];
    }
}

long long find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) return ST[i];
    else if (e < l || h < s) return 0;
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

    int N, Q; cin >> N >> Q;
    ST.resize(4*N);
    for (int i = 1; i <= N; i++) {
        int ipt; cin >> ipt;
        update(1, 1, N, i, ipt);
    }

    while (Q--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << find(1, 1, N, x, y) << '\n';
        update(1, 1, N, a, b);
    }

    return 0;
}
