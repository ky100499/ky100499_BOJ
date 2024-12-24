#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    priority_queue<int> pq;
    while (N--) {
        int a; cin >> a;
        if (a) {
            while (a--) {
                int g; cin >> g;
                pq.push(g);
            }
        }
        else if (!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else cout << "-1\n";
    }

    return 0;
}
