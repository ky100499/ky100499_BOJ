#include <iostream>
#include <vector>

using namespace std;

vector<int> A, ST;

void init(int i, int l, int h)
{
    if (l == h) {
        ST[i] = l;
    }
    else {
        int m = (l+h)/2;
        init(i*2, l, m);
        init(i*2+1, m+1, h);
        ST[i] = A[ST[2*i]] > A[ST[2*i+1]] ? ST[2*i+1] : ST[2*i];
    }
}

void update(int i, int l, int h, int k)
{
    if (l < h) {
        int m = (l+h)/2;
        if (l <= k && k <= m)
            update(2*i, l, m, k);
        else if (m < k && k <= h)
            update(2*i+1, m+1, h, k);

        ST[i] = A[ST[2*i]] > A[ST[2*i+1]] ? ST[2*i+1] : ST[2*i];
    }
}

int find(int i, int l, int h, int s, int e)
{
    if (s <= l && h <= e) {
        return ST[i];
    }
    else if (e < l || h < s) {
        return 0;
    }
    else {
        int m = (l+h)/2;
        int i1 = find(i*2, l, m, s, e), i2 = find(i*2+1, m+1, h, s, e);
        return A[i1] > A[i2] ? i2 : i1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    A.resize(N+1);
    A[0] = 2e9;
    ST.resize(4*N);
    for (int i = 1; i <= N; i++) cin >> A[i];
    init(1, 1, N);

    int M; cin >> M;
    while (M--) {
        // for (auto st : ST)
        //     cout << st << ' ';
        // cout << '\n';

        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            A[b] = c;
            update(1, 1, N, b);
        }
        else {
            cout << find(1, 1, N, b, c) << '\n';
        }
    }
}
