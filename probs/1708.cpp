#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<ll, ll>;

const int MAX = 1e5;
const double INF = 1e9;

pi A[MAX];

ll cp(pi a, pi b)
{
    return a.first*b.second - a.second*b.first;
}

int ccw(pi a, pi b, pi c)
{
    ll z = cp({b.first-a.first, b.second-a.second}, {c.first-b.first, c.second-b.second});
    return z > 0 ? 1 : z < 0 ? -1 : 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    pi O = {1e9, 1e9};
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        O = min(O, A[i]);
    }
    sort(A, A+N, [=](pi a, pi b) {
        ll c = ccw(O, a, b);
        if (c > 0) return true;
        else if (c < 0) return false;
        else return a < b;
    });

    vector<pi> cvx(N);
    int size = 0;
    for (int i = 0; i < N; i++) {
        auto [x, y] = A[i];
        while (size >= 2 && ccw(cvx[size-2], cvx[size-1], {x, y}) != 1) size--;
        cvx[size++] = {x, y};
    }

    if (size > 2 && ccw(cvx[size-2], cvx[size-1], cvx[0]) == 0) size--;

    cout << size << '\n';

    return 0;
}
