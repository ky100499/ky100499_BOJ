#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e5;

int A[MAX+2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    memset(A, 0, sizeof A);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[x]++;
    }

    ll ans = 0;
    queue<int> q;
    for (int i = 1; i <= MAX+1; i++) {
        for (int j = q.size(); j; j--) {
            int x = q.front(); q.pop();
            if (A[i]) {
                q.push(x);
                A[i]--;
            }
            else ans += (ll)(i-1) * (i-x);
        }
        while (A[i]--) q.push(i);
    }

    cout << ans << '\n';

    return 0;
}
