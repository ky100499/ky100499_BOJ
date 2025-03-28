#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= 2*N-1; i++)
        cout << string(abs(N-i), ' ') + string(2*(N-abs(N-i))-1, '*') << '\n';

    return 0;
}
