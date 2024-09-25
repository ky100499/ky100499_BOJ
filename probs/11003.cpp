#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, L; cin >> N >> L;
    deque<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        int n; cin >> n;

        while (!q.empty() && q.back().first > n) q.pop_back();
        q.push_back({n, i});
        while (q.front().second <= i-L) q.pop_front();

        cout << q.front().first << ' ';
    }
    cout << '\n';

    return 0;
}
