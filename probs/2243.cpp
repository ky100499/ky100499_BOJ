#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+1;

int ST[4*MAX];

void update(int i, int l, int h, int k, int v)
{
    ST[i] += v;

    if (l != h) {
        int m = (l+h)/2;
        if (k <= m) update(2*i, l, m, k, v);
        else update(2*i+1, m+1, h, k, v);
    }
}

int solve(int i, int l, int h, int n)
{
    ST[i]--;

    if (l == h) return l;

    int m = (l+h)/2;
    if (n <= ST[2*i]) return solve(2*i, l, m, n);
    else return solve(2*i+1, m+1, h, n-ST[2*i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    memset(ST, 0, sizeof ST);
    while (N--) {
        int a, b; cin >> a >> b;

        if (a == 1) {
            cout << solve(1, 1, MAX, b) << '\n';
        }
        else {
            cin >> a;
            update(1, 1, MAX, b, a);
        }
    }

    return 0;
}
