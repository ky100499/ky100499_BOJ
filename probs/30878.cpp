#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M; cin >> M;
    int a = M*M*M + 3*M*M*(60-M),
        b = 60*60*60,
        g = gcd(a, b);

    cout << a/g << '/' << b/g << '\n';

    return 0;
}
