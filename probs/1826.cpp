#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        A[i] = {a, b};
    }
    sort(A.begin(), A.end());
    int L, P; cin >> L >> P;

    int ans = 0;
    int e = P, i = 0;
    priority_queue<int> pq;
    while (e < L) {
        while (i < N && A[i].first <= e)
            pq.push(A[i++].second);
        if (pq.empty()) break;

        e += pq.top();
        pq.pop();
        ans++;
    }

    cout << (e < L ? -1 : ans) << '\n';

    return 0;
}
