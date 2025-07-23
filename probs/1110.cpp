#include <bits/stdc++.h>

using namespace std;

int dgtSum(int n)
{
    int ret = 0;
    while (n) {
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, n, c = 0; cin >> N; n = N;

    while (++c) {
        n = (n%10)*10 + dgtSum(n)%10;
        if (n == N) break;
    }

    cout << c << '\n';

    return 0;
}
