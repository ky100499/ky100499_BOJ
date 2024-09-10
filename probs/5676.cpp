#include <iostream>
#include <vector>

using namespace std;

vector<int> ST, X;

void init(int i, int l, int h)
{
    if (l == h) {
        if (X[l])
            ST[i] = X[l] / abs(X[l]);
        else
            ST[i] = 0;
    }
    else {
        int m = (l+h)/2;
        init(2*i, l, m);
        init(2*i+1, m+1, h);
        ST[i] = ST[2*i] * ST[2*i+1];
    }
}

void update(int i, int l, int h, int k, int v)
{
    if (l == h) {
        if (v)
            ST[i] = v / abs(v);
        else
            ST[i] = 0;
    }
    else {
        int m = (l+h)/2;
        if (l <= k && k <= m)
            update(2*i, l, m, k, v);
        else if (m < k && k <= h)
            update(2*i+1, m+1, h, k, v);
        ST[i] = ST[2*i] * ST[2*i+1];
    }
}

int find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e)
        return ST[i];
    else if (e < l || h < s)
        return 1;
    else {
        int m = (l+h)/2;
        return find(2*i, l, m, s, e) * find(2*i+1, m+1, h, s, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    char ans[] = { '-', '0', '+' };

    while (1) {
        int N, K; cin >> N >> K;
        if (cin.eof()) break;

        ST.resize(4*N);
        X.resize(N+1);
        for (int i = 1; i <= N; i++) cin >> X[i];

        init(1, 1, N);

        while (K--) {
            char op; int i, j; cin >> op >> i >> j;
            if (op == 'C')
                update(1, 1, N, i, j);
            else
                cout << ans[find(1, 1, N, i, j)+1];
        }
        cout << '\n';
    }
}
