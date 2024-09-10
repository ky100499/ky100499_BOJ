#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int MOD = 1e9+7;

vector<ll> ST;

void init(int i, int l, int h)
{
    if (l == h) {
        cin >> ST[i];
    }
    else {
        int m = (l+h)/2;
        init(i*2, l, m);
        init(i*2+1, m+1, h);
        ST[i] = ST[2*i] * ST[2*i+1] % MOD;
    }
}

void update(int i, int l, int h, int k, int v)
{
    if (l == h) {
        ST[i] = v;
    }
    else {
        int m = (l+h)/2;
        if (l <= k && k <= m)
            update(2*i, l, m, k, v);
        else if (m < k && k <= h)
            update(2*i+1, m+1, h, k, v);
        ST[i] = ST[2*i] * ST[2*i+1] % MOD;
    }
}

ll find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) {
        return ST[i];
    }
    else if (e < l || h < s) {
        return 1;
    }
    else {
        int m = (l+h)/2;
        return find(i*2, l, m, s, e) * find(i*2+1, m+1, h, s, e) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    ST.resize(4*N);
    init(1, 0, N-1);

    M += K;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1)
            update(1, 0, N-1, b-1, c);
        else
            cout << find(1, 0, N-1, b-1, c-1) << '\n';
    }
}
