#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int N, ans[10], mat[10];
pi A[10], B[10];

int ccw(pi a, pi b, pi c)
{
    int n = (b.first-a.first) * (c.second-b.second) - (b.second-a.second) * (c.first-b.first);
    return n == 0 ? 0 : n/abs(n);
}

bool cross(int i, int j, int u, int v)
{
    int c1 = ccw(A[i], B[j], A[u]) * ccw(A[i], B[j], B[v]),
        c2 = ccw(A[u], B[v], A[i]) * ccw(A[u], B[v], B[j]);

    if (c1 == 0 && c2 == 0) return min(A[i], B[j]) <= max(A[u], B[v]) && min(A[u], B[v]) <= max(A[i], B[j]);
    else return c1 <= 0 && c2 <= 0;
}

bool bt(int i)
{
    if (i == N) {
        for (int j = 0; j < N; j++) cout << ans[j]+1 << '\n';
        return 1;
    }

    for (int j = 0; j < N; j++) {
        if (!mat[j]) {
            int cr = 0;
            for (int k = 0; k < i; k++) cr |= cross(k, ans[k], i, j);
            if (cr) continue;

            mat[j] = 1;
            ans[i] = j;

            if (bt(i+1)) return 1;

            mat[j] = 0;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    for (int i = 0; i < N; i++) cin >> B[i].first >> B[i].second;

    memset(mat, 0, sizeof mat);
    bt(0);

    return 0;
}
