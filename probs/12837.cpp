#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> ST;

void update(int i, int l, int h, int k, int v)
{
    if (l == h) {
        ST[i] += v;
    }
    else {
        int m = (l+h)/2;
        if (l <= k && k <= m)
            update(2*i, l, m, k, v);
        else if (m < k && k <= h)
            update(2*i+1, m+1, h, k, v);
        ST[i] = ST[2*i] + ST[2*i+1];
    }
}

ll find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e)
        return ST[i];
    else if (e < l || h < s)
        return 0;
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

    int N, Q; cin >> N >> Q;
    ST.resize(4*N, 0);

    while (Q--) {
        int op, p, q; cin >> op >> p >> q;
        if (op == 1)
            update(1, 1, N, p, q);
        else
            cout << find(1, 1, N, p, q) << '\n';
    }

    return 0;
}
