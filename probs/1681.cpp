#include <bits/stdc++.h>

using namespace std;

bool in(int n, int l)
{
    while (n) {
        if (n%10 == l) return 1;
        n /= 10;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, L, c = 0; cin >> N >> L;

    int i = 0;
    while (c < N) if (!in(++i, L)) c++;

    cout << i << '\n';

    return 0;
}
