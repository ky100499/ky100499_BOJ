#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5,
          INF = 1e9;

pi A[MAX];

int dist(pi a, pi b)
{
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int sq(int a)
{
    return a*a;
}

int solve(int l, int h)
{
    if (l >= h) return INF;

    int m = (l+h)/2,
        d = min(solve(l, m), solve(m+1, h));

    vector<pi> tmp; tmp.push_back(A[m]);
    for (int i = m-1; i >= l; i--) {
        if (sq(A[i].first - A[m].first) >= d) break;
        tmp.push_back(A[i]);
    }
    for (int i = m+1; i < h; i++) {
        if (sq(A[i].first - A[m].first) >= d) break;
        tmp.push_back(A[i]);
    }
    sort(tmp.begin(), tmp.end(), [](pi a, pi b) { return a.second == b.second ? a.first < b.first : a.second < b.second; });

    for (int i = 0; i < tmp.size(); i++) {
        for (int j = i+1; j < tmp.size(); j++) {
            if (sq(tmp[j].second - tmp[i].second) >= d) break;
            d = min(d, dist(tmp[i], tmp[j]));
        }
    }

    return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    sort(A, A+N);

    cout << solve(0, N) << '\n';

    return 0;
}
