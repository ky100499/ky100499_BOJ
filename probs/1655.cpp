#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    priority_queue<int> L;
    priority_queue<int, vector<int>, greater<int>> R;

    while (N--) {
        int x; cin >> x;

        if (L.empty() || x <= L.top()) L.push(x);
        else R.push(x);

        while (L.size() > R.size()) {
            R.push(L.top()); L.pop();
        }
        while (L.size() < R.size()) {
            L.push(R.top()); R.pop();
        }

        cout << L.top() << '\n';
    }

    return 0;
}
