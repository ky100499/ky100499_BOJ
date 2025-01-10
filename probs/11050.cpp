#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    if (n < 2) return 1;
    else return n * fact(n-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    cout << fact(N) / fact(K) / fact(N-K) << '\n';

    return 0;
}
