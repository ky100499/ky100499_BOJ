#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cout << string(5*N, '@') << '\n';
    for (int i = 0; i < 3*N; i++) cout << string(N, '@') << '\n';
    for (int i = 0; i < N; i++) cout << string(5*N, '@') << '\n';

    return 0;
}
