#include <bits/stdc++.h>

using namespace std;

void solve(int n, int s, int t, int m)
{
    if (!n) return;

    solve(n-1, s, m, t);
    cout << s << ' ' << t << '\n';
    solve(n-1, m, t, s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    cout << (1<<N)-1 << '\n';
    solve(N, 1, 3, 2);

    return 0;
}
