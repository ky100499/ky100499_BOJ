#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

vector<pi> A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N; A.reserve(2*N);
    while (N--) {
        int u, v; cin >> u >> v;
        A.emplace_back(u, 1);
        A.emplace_back(v, -1);
    }
    sort(A.begin(), A.end());
    int K; cin >> K;

    N = 0;
    for (auto [_, d] : A) {
        N += d;
        if (N > K) break;
    }

    cout << (N == 0) << '\n';

    return 0;
}
