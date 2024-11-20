#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int A[MAX], ST[4*MAX], N, ans = 0;

void init(int i, int l, int h)
{
    if (l == h) ST[i] = l;
    else {
        int m = (l+h)/2;
        init(2*i, l, m);
        init(2*i+1, m+1, h);
        ST[i] = A[ST[2*i]] > A[ST[2*i+1]] ? ST[2*i+1] : ST[2*i];
    }
}

int find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) return ST[i];
    else if (e < l || h < s) return -1;
    else {
        int m = (l+h)/2;
        int f1 = find(2*i, l, m, s, e),
            f2 = find(2*i+1, m+1, h, s, e);

        if (f1 == -1 && f2 == -1) return -1;
        else if (f1 == -1) return f2;
        else if (f2 == -1) return f1;
        else return A[f1] > A[f2] ? f2 : f1;
    }
}

void solve(int s, int e)
{
    int m = find(1, 0, N-1, s, e);
    ans = max(ans, A[m] * (e-s+1));
    if (s < m) solve(s, m-1);
    if (m < e) solve(m+1, e);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    init(1, 0, N-1);
    solve(0, N-1);
    cout << ans << '\n';

    return 0;
}
