#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M, N; cin >> M >> N;
    int m = sqrt(M), n = sqrt(N);
    if (m*m < M) m++;

    if (m > n) cout << -1 << '\n';
    else {
        int s = 0, x = m;
        while (x <= n) {
            s += x*x;
            x++;
        }
        cout << s << '\n' << m*m << '\n';
    }

    return 0;
}
